def getTemplate():
    template = """\\documentclass[9pt, a4paper, notitlepage]{extreport}
\\usepackage{RFpkg}
\\kactlcontentdir{../}
%university
%team
%contest
\enablecolors
%darkmode

%Add header 
\\fancyhf{}
\\renewcommand{\headrulewidth}{0pt}
\\fancyhead[L]{\MakeUppercase\leftmark}
\\fancyhead[C]{\\thepage}

\\begin{document}
    %addTeamPage
    %addTitle
    \\begin{multicols*}{3}
    \setcounter{tocdepth}{1}
    %addToc
    \\pagestyle{fancy}
    %content	
    \end{multicols*}
    % \\begin{multicols*}{3}
    \\begin{appendices}
        %addAppendix
    \\end{appendices}
    % \\end{multicols*}
\\end{document}"""
    return template


