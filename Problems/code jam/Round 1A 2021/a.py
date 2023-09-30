import sys


# sys.stdin = open(path + name + ".in")
# sys.stdout = open(path + name + ".out", "w")

testCases = int(input())

for testCase in range(1, testCases + 1):
    n = int(input())
    line = input().split()
    a = [int(x) for x in line]
    ans =0
    for i in range(1,n):
        while a[i]<=a[i-1]:
            ans = ans+1
            a[i]= a[i]*10
            x = 0
            flag = 0
            for j in  range(0,10):
                if a[i]+j>a[i-1]:
                    flag = 1
                    x = j
                    break
            if flag:
                a[i]= a[i]+x
                break
    print(a)
    print("Case #" + str(testCase) + ": " + ("%.0f" % ans))