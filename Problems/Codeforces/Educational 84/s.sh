for((i = 1; ; ++i)); do
    echo $i
    ./gen.out $i > in
    ./a.out < in 
done
