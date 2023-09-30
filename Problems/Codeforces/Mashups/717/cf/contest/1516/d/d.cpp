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
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

map<int,int> fact;
void factorize(int n){
    while(n>1){
        fact[lp[n]]++;
        n/=lp[n];
    }
}

signed main(){__
	int t= 1,n,q,l,r;
    criba();
    while(t--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,int> idx;
        vector<int> next(n);
        for(int i = n-1;i>=0;i--){
            fact.clear();
            factorize(nums[i]);
            next[i] = n;
            for(auto c:fact){
                if(idx.count(c.first))
                    next[i] = min(next[i],idx[c.first]);
                idx[c.first] = i;
            }
            if(i!=n-1)next[i] = min(next[i],next[i+1]);
        }
        // for(auto c:next)cout<<c<<" ";
        // cout<<endl;
        vector<vector<int>> dp(n+1,vector<int>(30,-1));
        for(int i = 0;i<n;i++)
            dp[i][0] = next[i];
        for(int i = 1;i<30;i++){
            for(int j = 0;j<n;j++){ 
                if(dp[j][i-1]==-1)continue;
                dp[j][i] = dp[dp[j][i-1]][i-1];
            }
        }
        for(int i = 0;i<q;i++){
            cin>>l>>r;
            l--,r--;
            int ans = 0;
            for(int j = 29;j>=0;j--){
                if(dp[l][j]!=-1 &&dp[l][j]<=r){
                    l = dp[l][j];
                    ans +=(1<<j);
                }
            }
            cout<<ans+1<<endl;
        }
    }
    return 0;
}  

