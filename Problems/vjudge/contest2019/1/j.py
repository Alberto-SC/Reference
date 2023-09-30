# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import sys
t = int(input())
while(t):
	t = t-1
	query = input()
	a,b,m = query.split()
	a = int(a)
	b = int(b)
	m = int(m)
    if(k&1):
        print(a-b*(k/2)+a+"\n")
    elif(not(k&1)):
        if(a==b):
            print(0+"\n")
        else:
            print((a-b)*(k/2)+"\n")
    elif(k ==1):
        print(a)