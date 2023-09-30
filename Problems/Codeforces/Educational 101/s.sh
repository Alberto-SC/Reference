for((i = 199900;i<200000;i++)); do
    echo "1 " $i > in
    ./a.out <in
done