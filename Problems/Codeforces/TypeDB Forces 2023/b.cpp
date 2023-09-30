#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 10000000;
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

signed main(){__
    int T = 1,n;
    cin>>T;
    criba();
    while(T--){
        cin>>n;
        map<int,int> mp;
        for(auto p:primes){
            if(p*p>n)break;
            while(n%p==0){
                mp[p]++;
                n/=p;
            }
        }
        if(n>1)mp[n]++;

        int ans = 0;
        
        while(mp.size()){
            int x = 1;
            vector<int> to_erase;
            for(auto &c:mp){
                x*=c.first;
                c.second--;
                if(c.second == 0){
                    to_erase.push_back(c.first);
                }
            }    
            for(auto c:to_erase){
                mp.erase(c);
            }
            ans+=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}