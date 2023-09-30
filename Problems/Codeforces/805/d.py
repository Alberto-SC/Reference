from sys import stdin

for tc in range(int(stdin.readline())):
    s = stdin.readline()
    p = int(stdin.readline())

    sum = 0
    pos = [[] for i in range(26)]
    need = [True for i in range(len(s)-1)]
    for i in range(len(s)-1):
        pos[ord(s[i])-ord('a')].append(i)
        sum+=ord(s[i])-ord('a')+1

    idx = 25
    while(sum>p):
        if(len(pos[idx])==0):
            idx-=1
            continue
        sum-=idx+1
        element = pos[idx].pop()
        
        need[element] = False
        
    for i in range(len(s)-1):
        if(need[i]):
            print(s[i],end='')
    print()