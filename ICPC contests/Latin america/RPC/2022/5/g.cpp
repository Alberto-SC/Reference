#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


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
    for(lli a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(n == a) return true;
        i128 residuo = powerMod(a, d, n);
        if(residuo == 1 or residuo == n-1) continue;
        lli x = s;
        while(--x){
            residuo = residuo * residuo % n;
            if(residuo == n-1) break;
        }
        if(x==0) return false;
    }
    return true; //Probability = 1 - (1/4)^size_of(vector_a)
}


signed main(){__
    lli l,r;
    cin>>l>>r;
    vector<string> S;
    S.push_back("2");
    for(int i = 1;i<=999999;i++){
        string s = to_string(i);
        if(s[0]== '2' || s[0]== '4' || s[0] == '6' || s[0] == '8')continue;
        reverse(s.begin(),s.end());
        string t = s;
        reverse(s.begin(),s.end());
        string s2 = s.substr(0,s.size()-1);
        reverse(s2.begin(),s2.end());
        string t2 =s2;
        string x = s+t;
        if(stoll(x)<=1e12)
            S.push_back(s+t);
        x = s+t2; 
        if(stoll(x)<=1e12)
            S.push_back(s+t2);
    }
    vector<lli> valid;
    for(auto c:S){
        lli number = stoll(c);
        if (isPrimeMillerRabin(number)){
            valid.push_back(number);
        }
    }
    sort(valid.begin(),valid.end());
    int idxl = lower_bound(valid.begin(),valid.end(),l)-valid.begin();
    int idxr = upper_bound(valid.begin(),valid.end(),r)-valid.begin();
    cout<<idxr-idxl<<endl;
}   