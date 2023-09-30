#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
map<int,int> fact;
const int N = 10000000;
vector<int> lp(N+1);
vector<int> primes;
void criba(){
    for(int i = 2;i<=N;i++){
        if(lp[i]==0){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j = 0;j<primes.size() && primes[j]<=lp[i] && i*primes[j]<=N;j++){
            lp[i*primes[j]] = primes[j];
        }
    }
}

void factorize(int n){
    for(auto p:primes){
        if((p*p)>n)break;
        while(n%p==0){
            fact[p]++;
            n/=p;
        }
    }
    if(n>1)fact[n]++;
}

signed main(){__
    int t,n;
    criba();
    cin>>t;
    while(t--){
        cin>>n;
        fact.clear();
        factorize(n);
        int ans = 0;
        for(auto c:fact){
            ans = max(ans,c.first);
        }
        cout<<ans<<endl;
    }
    return 0;
}
