#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

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

unordered_map<int,int> mp;

void factorize(int n){
    map<int,int> f;
    for(auto p:primes){
        if(p*p>n)break;
        if(n%p==0){
            mp[p]++;
        }
        while(n%p==0){
            n/=p;
            // f[p]++;
        }
    }
    // for(auto c:f)cout<<c.first<<" "<<c.second<<endl;
    // cout<<endl;
    if(n>1)mp[n]++;
}

signed main(){__
  int T,n;
  criba();
  cin>>T;
  while(T--){
    cin>>n;
    mp.clear();
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        factorize(nums[i]);
    }

    bool flag = false;
    for(auto c:mp){
        // cout<<c.first<<" "<<c.second<<endl;
        if(c.second>1)flag = true;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
