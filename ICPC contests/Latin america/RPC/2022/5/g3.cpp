#include <bits/stdc++.h>

using namespace std;
#define lli long long int
#define i128 __int128

i128 powerMod(i128 a, i128 b, i128 mod) {
    i128 res = 1; 
    while(b) {
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}


//22
bool isPrimeMillerRabin(lli n)
{
    if(n < 2) return false;
    if(n <= 3) return true;
    if( ~n & 1) return false;
    lli d = n-1, s = 0; //n-1 = 2^s*k
    for(;(~d&1); d>>=1, s++); //d = k
    for(lli a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if(n == a) return true;
        i128 residuo = powerMod(a, d, n);
        if(residuo == 1 or residuo == n-1) continue;
        lli x = s;
        while(--x)
        {
            residuo = residuo * residuo % n;
            if(residuo == n-1) break;
        }
        if(x==0) return false;
    }
    return true; //Probability = 1 - (1/4)^size_of(vector_a)
}
lli comp2(int x) {
    lli ret = x;
    lli ret2 = 0;
    while (x >= 10) {
        ret *= 10;
        x /= 10;
        ret2 *= 10;
        ret2 += (x % 10);
    }
    ret += ret2;
    return ret;
}


lli comp(lli x, lli y) {
    int i = 2;
    lli j = comp2(i);
    lli ans = 0;
    while (j < x) {
        i++;
        j = comp2(i);
    }
    while (j <= y) {
        ans += isPrimeMillerRabin(j);
        i++;
        j = comp2(i);
    }
    return ans + (x <= 11 && y >= 11);
}

#define MAX 400010

int main() {
    lli lo, hi;
    cin >> lo >> hi;
    cout << comp(lo, hi) << endl;
    return 0;
}