green=$(tput setaf 71);
red=$(tput setaf 12);
blue=$(tput setaf 32);
orange=$(tput setaf 178);
bold=$(tput bold);
reset=$(tput sgr0);

g++ -std=c++17 gen.cpp -o generator || { echo ${bold}${orange}Compilation Error in ${reset} gen.cpp; exit 1; }
g++ -std=c++17 $1.cpp -o original || { echo ${bold}${orange}Compilation Error${reset} in $1.cpp; exit 1; }
g++ -std=c++17 $2.cpp -o brute || { echo ${bold}${orange}Compilation Error${reset} in $2.cpp; exit 1; }

if [ $# -eq 2 ]
    then
        max_tests=2000 
    else
        max_tests=$3
fi

diff_found=0
i=1
while [ $i -le $max_tests ]
do
    ./generator > input1
    ./original < input1 > original_output #|| {echo failed; exit 1;}
    ./brute < input1 > brute_output
    if diff --tabsize=1 -F --label --side-by-side --ignore-space-change original_output brute_output > dont_show_on_terminal; then
        echo "${orange}test_case #$i: ${bold}${green}AC${reset}"
    else
        echo "${orange}test_case #$i: ${bold}${red}WA${reset}"
        diff_found=1
        break
    fi
    i=$((i+1))
done

if [ $diff_found -eq 1 ]
then
    echo "${blue}Input: ${reset}"
    cat input1
    echo ""

    echo "${blue}Output: ${reset}"
    cat original_output
    echo ""

    echo "${blue}Expected: ${reset}"
    cat brute_output
    echo ""
    notify-send "Wrong Answer"
else
    notify-send "Accepted"
    rm input1
fi

rm generator
rm original
rm brute
rm original_output
rm brute_output
rm dont_show_on_terminal