#!/bin/bash
currentLine=$(printf '%0.1s' "0"{1..200}) 
id=1
n=${#currentLine}
for (( c=1;c<=n;c++ ))
do 
  var=$(bc <<< $RANDOM%2 )
  if [ $var -eq 1 ];
  then
    currentLine=$(echo $currentLine | sed s/./'1'/$id)
  fi
  ((id++))
done 

#currentLine=$(printf '%0.1s' "0"{1..100} |sed s/./'1'/50)
echo $currentLine

iter=0
RED='\033[0;31m'
NC='\033[0m' # No Color
# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White


while : 
do
  newLine=$(printf '%0.1s' "0"{1..200})
  for (( i = 1;i<=n;i++ ))
  do 
    end=$(($i+2))
    segment=$(echo $currentLine| cut -c$i-$end)
    if  [ "$segment" = '110' ] || [ "$segment" = '101' ] || [ "$segment" = '011' ] || [ "$segment"  = '010' ] || [ "$segment" = '001' ];
    then 
      pos=$((i+1))
      newLine=$(echo $newLine | sed s/./'1'/$pos)
      printf "${On_Blue} ${NC}"
    else
    
      printf "${On_White} ${NC}"

      #echo "$segment -> 1 $i"
    fi 
  done
  echo ""
  
  currentLine=$newLine
  ((iter++))
done

