#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

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


const int M = 1e6;
const int mod = 998244353 ;
vector<int> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
int ncr(int n, int r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(){
   	for(int i = 2; i <= M; ++i){
		fact[i] = (int)fact[i-1] * i % mod;
		inv[i] = mod - (int)inv[mod % i] * (mod / i) % mod;
		invfact[i] = (int)invfact[i-1] * inv[i] % mod;
	}
}

signed main(){__
    int n;
    cin>>n;
    
    vector<int> nums(2*n);
    map<int,int> mp;
    for(auto &c:nums)cin>>c,mp[c]++;
    criba();
    calc();
    int sum = 0;
    vector<pair<int,int>> P;
    int total = fact[n];
    for(auto c:mp){
        if(lp[c.first]== c.first)
            P.push_back({c.first,c.second});
        else
            sum+=c.second,(total*=invfact[c.second])%=mod;
        
    }
    int k = fact[n];
    vector<vector<int>> DP(2*n+1,vector<int> (2*n+1));
    cout<<sum<<endl;
    DP[sum][0] = total;
    
    for(int i = 0;i<P.size();i++){
        vector<vector<int>> NDP(2*n+1,vector<int>(2*n+1));
        for(int s = sum;s<=n-P[i].second;s++){
            for(int k = 0;k<2*n;k++){
                (NDP[s+P[i].second-1][k+1] += DP[s][k]*invfact[P[i].second-1])%=mod;
                (NDP[s+P[i].second][k] += DP[s][k]*invfact[P[i].second])%=mod;
            }  
        }
        for(int i = 0;i<=2*n;i++){
            for(int j = 0;j<=2*n;j++){
                cout<<NDP[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        DP = NDP;
    }
    int ans = 0;
    for(int i = n;i<=2*n;i++){
        cout<<DP[n][i]<<" ";
        ans+=DP[n][i]*ncr(n,i);
        ans%=mod;
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
