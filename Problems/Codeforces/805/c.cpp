from sys import stdin,stdout
import bisect

for tc in range(int(stdin.readline())):
    stdin.readline()
    n,k = [int(x) for x in stdin.readline().split()]
    arr = [int(x) for x in stdin.readline().split()]

    pos = {}
    for i in range(len(arr)):
        if(arr[i] in pos):
            pos[arr[i]].append(i)
        else:
            pos[arr[i]] = []
            pos[arr[i]].append(i)

    for i in range(k):
        a,b = [int(x) for x in stdin.readline().split()]
        if( a in pos and b in pos):
            if pos[b][-1]>pos[a][0]:
                stdout.write("YES\n")
            else: 
                stdout.write("NO\n")
        else:
            stdout.write("NO\n")        
