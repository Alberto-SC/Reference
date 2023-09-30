#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
int bin_pow(int a,int b){
    int x=1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
const int N = 10000000;
int lp[N+1];


vector<int> primeFactorsSieve(int n){
    vector<int> primeFactors(n+1);
    for(int p = 2; p <= n; ++p){
        if(primeFactors[p]==0)
            for(int j = p; j <= n; j += p)
                primeFactors[j]++;
    }
    return primeFactors;
}


signed main(){__
	int t= 1,n,x,y;
    vector<int> sizes(1000007);
    vector<int> ac(1000007);
    vector<int> primeF = primeFactorsSieve(1000007);
    for(int i = 2;i<=1000000;i++){

        sizes[i] = primeF[i];
        ac[i] = ac[i-1]+sizes[i];
        ac[i]%=mod;
    }

    while(1){
        cin>>n>>x>>y;
        if(n==0)break;
        int sz = y-x;
        int z = bin_pow(2,sz-1);
        int a = ac[y-x];
        int ans = (a*z)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
