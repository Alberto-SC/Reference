import random
import math
# NO SIRVE
fact = {}
def gcd(a, b):
    a = abs(a)
    b = abs(b)
    while a:
        a, b = b % a, a
    return b


def brent(N):
    if N % 2 == 0:
        return 2
    y, c, m = random.randint(1, N - 1), random.randint(1, N - 1), random.randint(1, N - 1)
    g, r, q = 1, 1, 1
    while g == 1:
        x = y
        for i in range(r):
            y = ((y * y) % N + c) % N
        k = 0
        while k < r and g == 1:
            ys = y
            for i in range(min(m, r - k)):
                y = ((y * y) % N + c) % N
                q = q * (abs(x - y)) % N
            g = gcd(q, N)
            k = k + m
        r *= 2
    if g == N:
        while True:
            ys = ((ys * ys) % N + c) % N
            g = gcd(abs(x - ys), N)
            if g > 1:
                break

    return g
def trivial(n):
    if n == 2 or n == 3:    
        return 1
    if n <2:
        return 0
    if  n%2 == 0:
        return 2
    for p in range(3,int(n),2):
        if p*p >n:
            break
        else:
            if n%p == 0:
                return p
    if n <1000*10000:
        return 1
    return 0


def factorize(n):
    div = 0
    if n==1:
        return 1
    else:
        if n < 1000*1000:
            div = trivial(n)
            if div in fact:
                fact[div] = fact[div]+1
            else:
                fact[div] = 0
            print(div)
            factorize(n/div)
        else:
            div = brent(n)
            factorize(div)
            factorize(n/div)

n = int(input())
factorize(n)
