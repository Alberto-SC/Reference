#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M = 1e6;
const int mod =1e9+7;
vector<int> fact(M+1,1),inv(M+1,1),invfact(M+1,1);

int ncr(int n,int r){
    if(r<0|| r>n)return 0;
    return fact[n] * invfact[r]  % mod * invfact[n-r] %mod;
}

void calc(){
    for(int i = 2;i<=M;i++){
        fact[i] = fact[i-1]*i%mod;
        inv[i] = mod - inv[mod%i] * (mod/i) %mod;
        invfact[i] = invfact[i-1]* inv[i]%mod;
    }
}

signed main(){__
    int T = 1,n;
    calc();
    cin>>T;
    while(T--){
        cin>>n;
        cout<<ncr((2*n)-1,n)<<endl;

    }
    return 0;
}