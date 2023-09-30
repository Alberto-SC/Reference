#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<bin_pow(2,n-1)<<endl;
    }
    return 0;
}  
