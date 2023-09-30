#include <bits/stdc++.h>
using namespace std;
const int N = 10000000;
int lp[N+1];
vector<int> primes;

typedef long long int lli;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

#include <bits/extc++.h> 
struct chash { // large odd number for C
	const uint64_t C = lli(4e18 * acos(0)) | 71;
	lli operator()(lli x) const { return __builtin_bswap64(x*C); }
};

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

gp_hash_table<lli,int,chash> factorize(lli n){
    gp_hash_table<lli,int,chash> fact({},{},{},{},{1<<16});
    while(n>1){
        fact[lp[n]]++;
        n/=lp[n];
    }
    return fact;
}
const int mod = 1e9+7;
signed main(){
    lli n = 1e14;
    // cin>>n;
    criba();
    lli ans = 0;
    lli cont = 0;
    for(lli i = 2;i<=10000000;i++){
        gp_hash_table<lli,int,chash> fact = factorize(i*i);
        for(lli j = 1;j<=10000000;j++){
            gp_hash_table<lli,int,chash> fact2 = factorize(j);
            bool flag = true;
            for(auto c:fact2){
                if(fact.find(c.first)== fact.end()){
                    if(c.second>=2)flag = false;
                }
                else{
                    if(fact[c.first]&1)flag = false;
                    else if(fact[c.first]%2==0 && c.second>=2)flag = false;
                }
            }
            if(i*i*j<=n && flag){
                cont++;
                cout<<"I: "<<i*i<<" -> "<<i*i*j<<endl;
                (ans+=i*i)%=mod;

            }
            if(i*i*j>n)break;
        }    
        if(i*i>n)break;
    }
    cout<<cont<<endl;
    lli y = n-cont;
    (ans +=y)%=mod;
    cout<<ans<<endl;
    return 0;
}
// 100000000000003