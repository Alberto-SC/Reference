t = int(input())

def nDigits(x):
    cont = 0
    while x:
        x= x//10
        cont = cont+1
    return cont

for test in range(0,t):
    n = int(input())
    l1= 1
    l2 = 1
    f = 0
    current = 3
    if n ==1:
        print(1)
        continue
    while 1:
        f = l1+l2
        l2 = l1
        l1 = f
        if current>= n*4 and nDigits(f)== n:
            break
        current = current+1
    print(current)

