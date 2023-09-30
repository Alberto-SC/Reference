import sys
for line in sys.stdin:
    a,n = line.split()
    a = int(a)
    n = int(n)
    pow2 = 0
    pow5 = 0
    if(n ==0): 
        print("0 1")
        continue
    while (a%2==0):
        pow2+=1
        a//=2

    while (a%5==0 ):
        pow5+=1
        a//=5

    if(a>1):
        print("Precision Error")
        continue
    

    m = max(pow2*n,pow5*n)
    p2 = m-(pow2*n)
    p5 = m-(pow5*n)
    x = 1
    while(p2):
        x*=2
        p2-=1
    
    while(p5):
        x*=5
        p5-=1
    
    print(str(m)+" "+str(x))