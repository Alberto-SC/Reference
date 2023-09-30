#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int  ull;
typedef long long int lli;
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

bool isPrimeMillerRabin(lli n){
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



int main(){
    lli n,t;
    cin>>t;
    while(t--){
        cin>>n;
        if(isPrime(n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}