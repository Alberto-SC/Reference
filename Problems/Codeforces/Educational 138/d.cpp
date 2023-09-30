#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 998244353;

const int N = 1000000;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j){
            lp[i * primes[j]] = primes[j];
            if(i%primes[j]==0)break;
        }
    }
}

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
    int T = 1,n,m;
    criba();
    cin>>n>>m;
    int ans = m,last = m,mn = 1;
    int total =1,total2 = 0;
    ans%=mod;
    last%=mod;
    for(int i = 1;i<=n;i++){
        total*=(m%mod);
        total%=mod;
        total2+=total;
        total2%=mod;
    }
    for(int i = 2;i<=n;i++){
        mn*=lp[i]==i?i:1;
        if(mn>m)break;
        int z = m/mn;
        z%=mod;
        last*=z;
        last%=mod;
        ans+=last;
        ans%=mod;
    }
    ans = total2-ans;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    return 0;
}