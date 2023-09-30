s = input()
ans = 0
for c in s:
    ans+=ord(c)
print(chr(round(ans/len(s))))
