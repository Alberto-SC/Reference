#!/bin/bash

green=$(tput setaf 71);
red=$(tput setaf 12);
blue=$(tput setaf 32);
orange=$(tput setaf 178);
bold=$(tput bold);
reset=$(tput sgr0);

g++ $1.cpp
diff_found=0
lastIN=0
lastCorrect=0
while read -r line ; do
    ansFile=$(echo "$line" | sed  's/in/ans/') 
    echo $line $ansFile
    ./a.out <$line >out
    if diff --tabsize=1 -F --label --side-by-side --ignore-space-change out $ansFile > dont_show_on_terminal; then
        echo "${orange}test_case #$i: ${bold}${green}AC${reset}"
    else
        echo "${orange}test_case #$i: ${bold}${red}WA${reset}"
        echo "FAIL IN TEST $line"
        diff_found=1
        lastIN=$line
        lastCorrect=$ansFile
        break
    fi  
    # if [[ $(diff out )  ]]
done < <(find  -name "*.in" )

if [ $diff_found -eq 1 ]
then
    echo "${blue}Input: ${reset}"
    cat $lastIN
    echo ""

    echo "${blue}Output: ${reset}"
    cat out
    echo ""

    echo "${blue}Expected: ${reset}"
    cat $lastCorrect
    echo ""
    notify-send "Wrong Answer"
else
    notify-send "Accepted"
    rm input1
fi
