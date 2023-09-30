#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int m;
const int mod = 998244353;
int count(vector<int> &primes,int idx,int n){
    if(idx ==-1)return n;
    return count(primes,idx-1,n)-count(primes,idx-1,n/primes[idx]);
}

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

map<int,int> factorize(int n){
    map<int,int> f;
    for(auto p:primes){
        if(p*p>n)break;
        while(n%p==0){
            f[p]++;
            n/=p;
        }
    }
    if(n>1)f[n]++;
    return f;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    criba();
    while(T--){
        cin>>n>>m;
        vector<int> nums(n);

        for(auto &c:nums)cin>>c;
        bool flag = true;
        int ans = 1;
        for(int i = 1;i<n;i++){
            if(nums[i-1]%nums[i]){
                ans = 0;
                break;
            }
            map<int,int> f = factorize(nums[i-1]/nums[i]);
            vector<int> primes;
            for(auto c:f)primes.push_back(c.first);
            ans*=count(primes,primes.size()-1,m/nums[i]);
            ans%=mod;        
        }
        if(!flag)cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}