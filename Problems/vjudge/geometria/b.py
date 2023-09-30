import math
d,h,v,e = map(float, raw_input().split())
r = d/2
if v - (math.pi * r**2 * e) < 0:
    print("NO")
else:
    l = (v / (pi * r**2)) - e
    print("YES")
    print(h / l)