from __future__ import print_function
import sys
import getopt
import subprocess
import os
import re
import time
from beaupy import *
from beaupy.spinners import *
from tqdm import tqdm
from time import sleep
from progress.bar import IncrementalBar
from templateTex import getTemplate
from errors import *
import tempfile
import shutil
import signal

DEFAULT_IGNORE = [
    "tex",
    "build",
    "fonts",
    "__pycache__",
    "logs",
    "_minted-Reference",
    "appendix",
    "misc",
]

SPINNER_ANIMATION = [
        "[    ]",
        "[=   ]",
        "[==  ]",
        "[=== ]",
        "[ ===]",
        "[  ==]",
        "[   =]",
        "[    ]",
        "[   =]",
        "[  ==]",
        "[ ===]",
        "[====]",
        "[=== ]",
        "[==  ]",
        "[=   ]"
    ]

BUILD_DIRECTORY = os.getcwd()+'/build'

def signal_handler(sig, frame):
    console.print("[red]\nCtrl+C detected. Exiting the program.![/red]")
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

# Register the signal handler for Ctrl+C

def addContent(rootdir,TexFile,keepTex):
    subdir, dirs ,files = next(os.walk(rootdir))

    texContent = ""
    for dir in sorted(dirs, key = lambda x: (not x.endswith('contest'), x =='test')):
        if dir in DEFAULT_IGNORE:
            continue
        path,_,filesInside = next(os.walk(f'{rootdir}/{dir}'))
        texDirectory = os.path.join(path, 'Tex')

        if not os.path.exists(texDirectory):
            os.mkdir(texDirectory)

        texContentDir = f"\chapter{{{dir}}}\n"
        numberFiles = len(filesInside)
        bar = IncrementalBar(f'Processing {dir}', max=numberFiles,suffix='%(progress)d / %(remaining)d [%(percent).1f%% - %(elapsed)ds]')

        for file in sorted(filesInside, key=lambda x: (not x.endswith('.tex'),not x.endswith('.sh'), x)):
            bar.next()
            sleep(.01)
            extension = file.split('.')[-1]

            temp = file.split('_')
            fileCamelCase = temp[0] + ''.join(ele.capitalize() for ele in temp[1:])

            os.rename(os.path.join(path,file),os.path.join(path,fileCamelCase))

            try:
                if not extension in languagesExtensions and extension != "tex":
                    raise NotProgrammingLanguageOrText(path)
            except:
                continue


            if extension== "tex" and file != "chapter.tex":
                texContentDir += f"\import{{{fileCamelCase}}}\n"
            elif extension in ["sh" ,"bash", "txt"]:
                texContentDir += f"\kactlimport[-r]{{{fileCamelCase}}}\n"
            elif extension in languagesExtensions:
                texContentDir += f"\kactlimport{{{fileCamelCase}}}\n"
            else:
                continue

        print(texContentDir)
        bar.finish()

        outstream = open(os.path.join(f'{rootdir}/{dir}','chapter.tex'),'w')
        print(texContentDir, file=outstream)

        texContent += f"\kactlchapter{{{dir}}}\n"

    return texContent


def compile_latex_file(file_name):
    os.chdir(os.getcwd())
    latex_file_path = 'Reference.tex'

    output_directory = 'build/'

    try:
        # Check if the 'build' directory exists
        if os.path.exists(output_directory):
            # Remove the entire 'build' directory and its contents
            shutil.rmtree(output_directory)
            console.print("[blue]\nThe 'build' directory and its contents have been deleted.![/blue]")

        # Recreate the 'build' directory
        os.makedirs(output_directory)
        console.print("[blue]\nThe 'build' directory has been recreated.![/blue]")
    except Exception as e:
        print(f"An error occurred: {e}")


    # Define the command and its arguments
    command = [
        'xelatex',
        '-halt-on-error',
        '-file-line-error',
        '-shell-escape',
        '-interaction=nonstopmode',
        f'-output-directory={output_directory}',
        file_name
    ]
    try:
        result = subprocess.run(command, check=True, text=True)
        print(result.stdout)
        console.print("[blue]Running twice to ensure TOC is printed ![/blue]")
        result = subprocess.run(command, check=True, text=True)
        print(result.stdout)
        console.print("[green]You PDF was builded ![/green]")

    except subprocess.CalledProcessError as e:
        console.print("[red]LaTeX compilation failed. Error output: ![/red]")
        print(e.stderr)



def createAll():
    try:
        console.print("[cyan]--------- PyReference --------- ![/cyan]")
        item_options = [
            "Add front page",
            "Add title",
            "Add appendix",
            "Add table of contents",
            "Dark mode",
            "Build PDF"
        ]
        selected_options = [0,1,2,3,5]
        console.print("What do add to reference?")
        items = select_multiple(item_options,ticked_indices=selected_options, tick_character="✔", cursor_style="cyan")

        # directory = prompt('Main directory: ', target_type=str)
        Tex = getTemplate()

        if "Add front page" in items:
            console.print("Front page info: Leave blank if you don't want to add this information")
            universityNameLong = prompt('University name long: ', target_type=str,initial_value="Escuela Superior de Cómputo")
            universityNameShort = prompt('University name short: ', target_type=str,initial_value="ESCOM")
            universityLogo = prompt('University logo file (without extention and must be in this same dir): ', target_type=str,initial_value="ESCOM")
            teamName = prompt('Team name: ', target_type=str,initial_value="dESCOMprimidos.zip")
            teamMembers = prompt('Team members names separeted by ,: ', target_type=str,initial_value="Alberto Silva , Erick Santillan, Ulises Reyes")
            contestName = prompt('Contest: ', target_type=str,initial_value="ICPC Regional Finals 2022")
            date =  confirm("Add date?",cursor = '>',cursor_style = 'pink1',default_is_yes=True)
            if universityNameLong or universityNameShort or universityLogo :
                Tex = Tex.replace(r'%university', f"\\university{{{universityNameLong}}}{{{universityNameShort}}}{{{universityLogo}}}")
            if teamName:
                Tex = Tex.replace(r'%team', f"\\team{{{teamName}}}{{{teamMembers}}}")
            if contestName:
                if date:
                    Tex = Tex.replace(r'%contest', f"\\contest{{{contestName}}}{{\\today}}")
                else:
                    Tex = Tex.replace(r'%contest', f"\\contest{{{contestName}}}{{}}")

            Tex = Tex.replace(r"%addTeamPage",'\maketeampage')


        if "Add title" in items:
            console.print("Title")
            title = prompt('Title: ', target_type=str,initial_value="'Latin America Regional Finals' Edition")
            date =  confirm("Add date?",cursor = '>',cursor_style = 'pink1',default_is_yes=True)
            Tex = Tex.replace(r'%addTitle', f"\\maketitle{{{title}}}{{\\today}}")


        spinner = Spinner(SPINNER_ANIMATION, "Creating Tex file of your content...")
        spinner.start()

        rootdir = os.path.abspath(os.path.join(".", os.pardir))
        time.sleep(0.5)
        spinner.stop()

        content = addContent(rootdir,Tex,items)
        Tex = Tex.replace(r'%content', content)

        if "Add table of contents" in items:
            Tex = Tex.replace(r'%addToc','\\tableofcontents')
        if "Add appendix" in items:
            Tex = Tex.replace(r'%addAppendix','\\kactlchapter{appendix}')
        if "Dark mode" in items:
            Tex = Tex.replace(r'%darkmode','\\enableDarkMode')

        console.print("[green]Tex file generated ![/green]")
        print(Tex)

        with open(os.path.join(f'{rootdir}','tex/Reference.tex'),'w') as outstream:
            print(Tex, file=outstream)
            console.print("[green]You reference was builded and saved in: ![/green]", os.path.join(f'{rootdir}','tex/Reference.tex'))

        if "Build PDF" in items:
            compile_latex_file("Reference.tex")
    except KeyboardInterrupt:
        console.print("[red]\nCtrl+C detected. Exiting the program.![/red]")
        sys.exit(0)

def main():
    outstream = sys.stdout

    try:
        opts, args = getopt.getopt(sys.argv[1:], "ho:rc:", ["help", "createAll", "compile=", "output="])
        for option, value in opts:
            print(option,value)
            if option in ("-h", "--help"):
                print("This is the help section for this program")
                print()
                print("Available commands are:")
                print("\t -o --output")
                print("\t -h --help")
                print("\t -c --compile")
                print("\t -r --createAll")
                return
            if option in ("-c", "--compile"):
                compile_latex_file(value)
                return
            if option in ("-o", "--output"):
                outstream = open(value, "w")
            if option in ("-r", "createAll"):
                createAll()
                return

    except (ValueError, getopt.GetoptError, IOError) as err:
        print(str(err), file=sys.stderr)
        print("\t for help use --help", file=sys.stderr)
        return 2

if __name__ == "__main__":
    exit(main())
