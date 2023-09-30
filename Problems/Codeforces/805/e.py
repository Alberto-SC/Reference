from sys import stdin

for tc in range(int(stdin.readline())):
    n = int(stdin.readline())

    st1 = set()
    st2 = set()
    flag = True
    for i in range(n):
        a,b = [int(x) for x in stdin.readline().split()]
        if((not (a in st1)) and (not (b in st1)) and a!= b):
            st1.add(a)
            st1.add(b)
        elif ((not (a in st2)) and (not (b in st2)) and a!= b):
            st2.add(a)
            st2.add(b)
        else:
            flag = False
        
    if(flag):
        print("YES")
    else:
        print("NO")