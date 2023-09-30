# import print_function from __future__ 
from __future__ import print_function
import sys
import getopt
import subprocess

knownCommands = ['Author', 'Date', 'Description', 'Source', 'Time', 'Memory', 'License', 'Status', 'Usage', 'Details','Considerations','Problems']
requiredCommands = ['Description','Time']
languagesExtensions = ['c','cpp','py','java','h','rs','sh','txt','bashrc','vimrc']

def escape(input):
    input = input.replace('<', r'\ensuremath{<}')
    input = input.replace('>', r'\ensuremath{>}')
    return input

def pathescape(input):
    input = input.replace('\\', r'\\')
    input = input.replace('_', r'\_')
    input = escape(input)
    return input

def codeescape(input):
    input = input.replace('_', r'\_')
    input = input.replace('\n', '\\\\\n')
    input = input.replace('{', r'\{')
    input = input.replace('}', r'\}')
    input = input.replace('^', r'\ensuremath{\hat{\;}}')
    input = escape(input)
    return input

def ordoescape(input, esc=True):
    if esc:
        input = escape(input)
    start = input.find("O(")
    if start >= 0:
        bracketcount = 1
        end = start+1
        while end+1<len(input) and bracketcount>0:
            end = end + 1
            if input[end] == '(':
                bracketcount = bracketcount + 1
            elif input[end] == ')':
                bracketcount = bracketcount - 1
        if bracketcount == 0:
            return r"%s\bigo{%s}%s" % (input[:start], input[start+2:end], ordoescape(input[end+1:], False))
    return input

def addref(caption, outstream):
    caption = pathescape(caption).strip()
    print(r"\kactlref{%s}" % caption, file=outstream)

COMMENT_TYPES = [
    ('/**', '*/'),
    ("'''", "'''"),
    ('"""', '"""'),
]

def find_start_comment(source, start=None):
    first = (-1, -1, None)
    for s, e in COMMENT_TYPES:
        i = source.find(s, start)
        if i != -1 and (i < first[0] or first[0] == -1):
            first = (i, i + len(s), e)

    return first

def process(caption ,instream,outstream,listingslang,extended,appendix):
    knowncommands = ['Author', 'Date', 'Description', 'Source', 'Time', 'Memory', 'License', 'Status', 'Usage', 'Details','Considerations','Problems']
    requiredcommands = ['Description','Time']
    includelist = []
    error = ""
    warning = ""
    # Read lines from source file
    try:
        lines = instream.readlines()
    except:
        error = "Could not read source."
    nlines = list()
    for line in lines:
        if not line.strip():
            continue
        if line == '\n':
            continue
        if 'exclude-line' in line:
            continue
        if 'include-line' in line:
            line = line.replace('// ', '', 1)
        had_comment = "///" in line
        keep_include = 'keep-include' in line
        # Remove /// comments
        line = line.split("///")[0].rstrip()
        # Remove '#pragma once' lines
        if not extended:
            if 'exclude-from-here' in line:
                break 
        if line == "#pragma once":
            continue
        if had_comment and not line:
            continue
        # Check includes
        include = parse_include(line)
        if include is not None and not keep_include:
            includelist.append(include)
            continue
        nlines.append(line)
    # Remove and process multiline comments
    source = '\n'.join(nlines)
    nsource = ''
    start, start2, end_str = find_start_comment(source)
    end = 0
    commands = {}

    while start >= 0 and not error:
        nsource = nsource.rstrip() + source[end:start]
        end = source.find(end_str, start2)
        if end<start:
            error = "Invalid %s %s comments." % (source[start:start2], end_str)
            break
        comment = source[start2:end].strip()
        end += len(end_str)
        start, start2, end_str = find_start_comment(source, end)

        commentlines = comment.split('\n')
        command = None
        value = ""
        for cline in commentlines:
            allow_command = False
            cline = cline.strip()
            if cline.startswith('*'):
                cline = cline[1:].strip()
                allow_command = True
            ind = cline.find(':')
            if allow_command and ind != -1 and ' ' not in cline[:ind] and cline[0].isalpha() and cline[0].isupper():
                if command:
                    if command not in knowncommands:
                        error = error + "Unknown command: " + command + ". "
                    commands[command] = value.lstrip()
                command = cline[:ind]
                value = cline[ind+1:].strip()
            else:
                value = value + '\n' + cline
        if command:
            if command not in knowncommands:
                error = error + "Unknown command: " + command + ". "
            commands[command] = value.lstrip()

    if end>=0:
        nsource = nsource.rstrip() + source[end:]
    nsource = nsource.strip()

    if  len(commands) == 0: 
        warning = "No commands found, added as raw: "+caption
        processraw(caption, nsource, outstream, listingslang,warning,appendix)
        return 

    for rcommand in sorted(set(requiredcommands) - set(commands)):
        warning = warning + "Missing command, added as raw: " + rcommand + ". "
        processraw(caption, nsource, outstream, listingslang,warning,appendix)
        return 

    processwithcomments(caption, nsource, outstream, listingslang,extended,commands,includelist,appendix)


def processwithcomments(caption, nsource, outstream, listingslang,extended,commands,includelist,appendix):
    if listingslang in ['c++', 'Java']:
        hash_script = 'hash'
        p = subprocess.Popen(['sh', '../contest/%s.sh' % hash_script], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        hsh, _ = p.communicate(nsource.encode())
        hsh = hsh.split(None, 1)[0]
        hsh = hsh.decode()
        hsh = hsh + ', '
    else:
        hsh = ''
    out = []

    if not appendix:
        addref(caption, outstream)
    if commands.get("Description"):
        out.append(r"\defdescription{%s}" % escape(commands["Description"]))
    if commands.get("Considerations"):
        out.append(r"\defconsiderations{%s}" % escape(commands["Considerations"]))
    if commands.get("Usage"):
        out.append(r"\defusage{%s}" % codeescape(commands["Usage"]))
    if commands.get("Time"):
        out.append(r"\deftime{%s}" % ordoescape(commands["Time"]))
    if commands.get("Memory"):
        out.append(r"\defmemory{%s}" % ordoescape(commands["Memory"]))
    if includelist:
        out.append(r"\leftcaption{%s - %s}" % (caption,pathescape(", ".join(includelist))))
    else : 
        out.append(r"\leftcaption{%s}" % caption)
    if nsource:
        out.append(r"\rightcaption{%s%d lines}" % (hsh, len(nsource.split("\n"))))
    langstr = ", language="+listingslang


    if listingslang == "Python":
        out.append(r"\begin{lstlisting}[caption={%s}%s, mathescape=true]" % (pathescape(caption),langstr))
    else:
        out.append(r"\begin{lstlisting}[caption={%s}, mathescape=true]" % (pathescape(caption)))
    out.append(nsource)
    # out.append(r"\pathinputminted[tabsize=2,firstline=25,breaklines,fontsize=\small,mathescape,bgcolor=bg]{%s}{%s}" % (listingslang,caption))
    out.append(r"\end{lstlisting}")
    # out.append(r"\pathinputminted[tabsize=2,firstline=25,breaklines,fontsize=\small,mathescape,bgcolor=bg]{%s}{%s}" % (listingslang,caption))

    for line in out:
        print(line, file=outstream)

def processraw(caption, source, outstream, listingslang = 'raw',warning = "",appendix = False):
    if warning:
        print(r"\kactlwarning{%s: %s}" % (caption, warning), file=outstream)
    try:
        if not appendix:
            addref(caption, outstream)
        print(r"\leftcaption{%s}" % caption, file=outstream)
        print(r"\rightcaption{%d lines}" % len(source.split("\n")), file=outstream)
        print(r"\begin{lstlisting}[language=%s,caption={%s}]" % (listingslang, pathescape(caption)), file=outstream)
        print(source, file=outstream)
        print(r"\end{lstlisting}", file=outstream)
    except:
        print("\kactlerror{Could not read source.}", file=outstream)

def parse_include(line):
    line = line.strip()
    if line.startswith("// #include"):
        return line[11:].strip()
    return None

def getlang(input):
    return input.rsplit('.',1)[-1]

def getfilename(input):
    return input.rsplit('/',1)[-1]

def getTexFile(path,outstream):
    name = path.split('/')[-1]
    extension = path.split('.')[-1]

    if not extension in languagesExtensions:
        raise NotProgrammingLanguageOrText(path)
        return

    instream = getFile(path)
    commands,code,includeList = getCommands(instream) 

    missedCommands = []
    for mCommand in sorted(set(requiredCommands) - set(commands)):
        missedCommands.append(mCommand)

    try:
        if(len(missedCommands)>=1):
            raise IncompleteCommands(path,missedCommands)
    except IncompleteCommands as e:
        logger.error(e)
        if len(commands) ==0:
            if extension== 'cpp' or extension =='h':
                writeRaw(name,code,outstream,"c++")
            else:
                writeRaw(name,code,outstream)
            return 
        
        writeWithCommands(name,commands,code,includeList,outstream,extension)
        return 

    name = name.split('.')[0]
    writeWithCommands(name,commands,code,includeList,outstream,extension)
    return 


def main():
    print("\n python preprocesor")
    language = None
    caption = None
    instream = sys.stdin
    outstream = sys.stdout
    fileName = None
    print_header_value = None
    extended = False
    appendix = False
    raw = False
    try:
        opts, args = getopt.getopt(sys.argv[1:], "ho:i:l:c:e:ra", ["help", "output=", "input=", "language=", "caption=", "appendix"])
        for option, value in opts:
            print(option,value)
            if option in ("-h", "--help"):
                print("This is the help section for this program")
                print()
                print("Available commands are:")
                print("\t -o --output")
                print("\t -h --help")
                print("\t -i --input")
                print("\t -r --raw")
                print("\t -e --extended")
                return
            if option in ("-a", "--appendix"):
                appendix = True
            if option in ("-o", "--output"):
                outstream = open(value, "w")
            if option in ("-i", "--input"):
                instream = open(value)
                if language == None:
                    language = getlang(value)
                if caption == None:
                    caption = getfilename(value)
            if option in ("-l", "--language"):
                language = value
            if option in ("-c", "--caption"):
                caption = value
            if option in ("-e", "--extended"):
                extended = True
            if option in ("-r", "--raw"):
                raw = True
            if option == "--print-header":
                print_header_value = value
        if print_header_value is not None:
            print_header(print_header_value, outstream)
            return
        print(" * \x1b[1m{}\x1b[0m".format(caption))
        
        if raw:
            source = instream.read()
            processraw(caption, source, outstream,appendix=appendix)
        elif language in ["cpp", "cc", "c", "h", "hpp"]:
            process(caption, instream, outstream, 'c++',extended,appendix)
        elif language in ["java", "kt"]:
            process(caption, instream, outstream, 'Java',extended,appendix)
        elif language == "py":
            process(caption, instream, outstream, 'Python',extended,appendix)
        elif language == "sh":
            source = instream.read()
            processraw(caption, source, outstream, listingslang='bash',appendix=appendix)
        else:
            raise ValueError("Unkown language: " + str(language))

    except (ValueError, getopt.GetoptError, IOError) as err:
        print(str(err), file=sys.stderr)
        print("\t for help use --help", file=sys.stderr)
        return 2

if __name__ == "__main__":
    exit(main())
