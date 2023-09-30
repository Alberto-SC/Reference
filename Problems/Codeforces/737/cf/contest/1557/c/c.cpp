#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M = 1e6;
const int mod = 1e9+7;
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

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}


signed main(){__
	int t= 1,n,k;
    calc();
    cin>>t;
    while(t--){
        cin>>n>>k;
        int x = 0;
        for(int i = 0;i<=n-1;i+=2)
            (x+=ncr(n,i))%=mod;
        if(n&1){    
            int ans = 1;
            x++;
            x%=mod;
            for(int i = 0;i<k;i++)
                (ans*=x)%=mod;
            cout<<ans<<endl;
        }
        else{
            int ans = 1;
            for(int i = 0;i<k;i++)
                (ans*=x)%=mod;
            int aux = 1;
            for(int i = 0;i<k;i++){
                int R = k-(i+1);
                int total = bin_pow(2,n);
                (ans+=aux*bin_pow(total,R))%=mod;
                (aux*=x)%=mod;
            }
            cout<<ans<<endl;

        }
    }
    return 0;
}  
