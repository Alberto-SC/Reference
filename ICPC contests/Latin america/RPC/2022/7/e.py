import math 
x1 = -1500000 
y1 = -1499998
x2 = 499999 
y2 = 499999
x3 = -500000 
y3 = -499999

L = math.atan2(y3 -y1, x3 - x1)*180/math.pi
R = math.atan2(y2 -y1, x2 - x1)*180/math.pi

print(L,R)