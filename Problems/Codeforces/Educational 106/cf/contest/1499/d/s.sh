green=$(tput setaf 71);
red=$(tput setaf 12);
blue=$(tput setaf 32);
orange=$(tput setaf 178);
bold=$(tput bold);
reset=$(tput sgr0);

g++ -std=c++17 gen.cpp -o generator || { echo ${bold}${orange}Compilation Error in ${reset} gen.cpp; exit 1; }
g++ -std=c++17 d.cpp -o original || { echo ${bold}${orange}Compilation Error${reset} in $1.cpp; exit 1; }

if [ $# -eq 0 ]
    then
        max_tests=10 
    else
        max_tests=$3
fi

diff_found=0
i=1
while [ $i -le $max_tests ]
do
    ./generator > input1
    ./original < input1 > original_output #|| {echo failed; exit 1;}
    echo "${orange}test_case #$i: ${bold}${green}AC${reset}"
done


rm generator
rm original
rm original_output
rm dont_show_on_terminal