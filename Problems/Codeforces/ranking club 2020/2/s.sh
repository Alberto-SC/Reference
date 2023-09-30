for((i = 1; ; ++i)); do
    echo $i
    ./gen.out $i > in.txt
    ./a.out < in.txt > out1
    ./b.out < in.txt > out2
    diff -w out1 out2 || break
    # diff -w <(./a.out < in.txt) <(./b.out < in.txt) || break
done
