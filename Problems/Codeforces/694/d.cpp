#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
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
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}
map<int,int> fact;
void facts(int n) {
    while(n>1){
        fact[lp[n]]++;
        n/=lp[n];
    }
}

int main(){__
	lli t= 1,n,q,w;
    criba();
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<lli,lli> mp;
        lli ans1 = 0,ans2 = 0;
        for(int i = 0;i<n;i++){
            fact.clear();
            facts(nums[i]);
            lli aux = 1;
            for(auto c:fact){
                if(c.second&1)
                    aux*=c.first;
            }
            mp[aux]++;
        }
        for(auto c:mp){
            ans1 = max(ans1,c.second);
            if(c.second%2 ==0|| c.first ==1)ans2+=c.second;
        }
        ans2 = max(ans1,ans2);
        cin>>q;
        while(q--){
            cin>>w;
            if(w == 0)cout<<ans1<<endl;
            else cout<<ans2<<endl;
        }
    }
    return 0;
}  

