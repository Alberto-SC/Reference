#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M = 3e6+7;
const int mod = 1e9+7;;
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

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

const int maxn = 3000007;
int DP[maxn][3];

signed main(){__
	int t= 1,n,q,x;
    calc();
    int inv3 = mod_pow(3,mod-2);
    while(t--){
        cin>>n>>q;
        DP[0][0] = DP[0][1] = DP[0][2] = n;
        for(int i = 1;i<3*n;i++){
            DP[i][0] = ncr(3*n,i+1);
            (DP[i][0]-=2*DP[i-1][0]);
            (DP[i][0]-=DP[i-1][1]); 
            (DP[i][0]+=3*mod)%=mod; 
            (DP[i][0]*=inv3)%=mod; 
            DP[i][1] = (DP[i][0]+DP[i-1][0])%mod;
            DP[i][2] = (DP[i][1]+DP[i-1][1])%mod;
        }
        while(q--){
            cin>>x;
            int ans = 0;
            if(x == 3*n){
                cout<<1<<endl;
                continue;
            }
            (ans+=ncr(3*n,x))%=mod; 
            (ans+=DP[x][0])%=mod; 
            cout<<ans<<endl;
        }
    }
    return 0;
}  
