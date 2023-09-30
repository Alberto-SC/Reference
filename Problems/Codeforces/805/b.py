from sys import stdin, stdout
for tc in range(int(stdin.readline())):
    str = stdin.readline()

    mp = {}
    days = 0
    for i in range(0,len(str)-1):
        mp[str[i]] = True
        if(len(mp)>3):
            days+=1
            mp = {}
            mp[str[i]] = True
        # print(mp)

    if(len(mp)):
        days+=1
    print(days)