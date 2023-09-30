
#!/bin/bash
Draw=()

pad=$(printf '%0.1s' "_"{1..100})
for (( i=0;i<63;i++ ))
do 
    Draw+=($pad)
done 

read level
draw(){
    if [[ $1 -eq level ]]
    then 
        return 0
    fi 
    for (( i=0;i<$3;i++ ))
    do     
      nwLine=$(echo ${Draw[(${#Draw[@]}-1)-($4+$i)]} | sed s/./'1'/$2)
      Draw[(${#Draw[@]}-1)-($4+$i)]=$nwLine 
    done
    x1=$2
    x2=$2
    ((x1--))
    ((x2++))
    for (( i=0;i<$3;i++ ))
    do 
      nwLine=$(echo ${Draw[(${#Draw[@]}-1)-($4+$3+$i)]} | sed s/./'1'/$x1)
      Draw[(${#Draw[@]}-1)-($4+$3+$i)]=$nwLine 
      nwLine=$(echo ${Draw[(${#Draw[@]}-1)-($4+$3+$i)]} | sed s/./'1'/$x2)      
      Draw[(${#Draw[@]}-1)-($4+$3+$i)]=$nwLine 
      ((x1--))
      ((x2++))
    done 
    ((x1++))
    ((x2--))
    newLevel=$(expr $1 + 1)
    newSize=$(expr $3 / 2)
    newLine=$(expr $3 \* 2 + $4)
    
    draw $newLevel $x1 $newSize $newLine 
    newLevel=$(expr $1 + 1)
    newSize=$(expr $3 / 2)
    newLine=$(expr $3 \* 2 + $4)
    newX=$(expr $2 + $3 )
    draw $newLevel $newX $newSize $newLine

}
draw 0 50 16 0
for line in "${Draw[@]}"
do 
    echo $line
done 
