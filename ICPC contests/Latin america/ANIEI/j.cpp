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
const int N = 1000007;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

map<int,int> facts;

void factorize(int n){
    facts.clear();
    while(n>1){
        facts[lp[n]]++;
        n/=lp[n];
    }
}


signed main(){__
	int t= 1,n,x,y;
    criba();
    vector<int> sizes(1000007);
    vector<int> ac(1000007);
    for(int i = 2;i<=1000000;i++){
        factorize(i);
        sizes[i] = facts.size();
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
