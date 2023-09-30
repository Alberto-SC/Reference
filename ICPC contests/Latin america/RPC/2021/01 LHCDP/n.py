import sys
for line in sys.stdin:
    a,n = line.split()
    a = int(a)
    n = int(n)
    cont2 = 0
    cont5 = 0
    while a%2==0:
        a = a/2
        cont2 = cont2+1
    while a%5 ==0:
        a = a/5
        cont5 = cont5+1
    if a>1 and n!= 0:
        print("Precision Error")
        continue
    if n==0:
        print("0 1")    
        continue
    v = cont2*n
    w = cont5*n
    m = max(v,w)
    print(m,(2**(m-v))*(5**(m-w)))