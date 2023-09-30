#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M = 1e6;
const lli mod = 1e9+7;
vector<lli> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
lli ncr(lli n, lli r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(){
   	for(int i = 2; i <= M; ++i){
		fact[i] = (lli)fact[i-1] * i % mod;
		inv[i] = mod - (lli)inv[mod % i] * (mod / i) % mod;
		invfact[i] = (lli)invfact[i-1] * inv[i] % mod;
	}
}

int main(){__
	int t= 1,A,B,C,K,c;
    cin>>t;
    calc();
    while(t--){
        cin>>A>>B>>C>>K>>c;
        K-=c;
        if(K<0){
            cout<<0<<endl;
        }
        else{
            lli ans =0;
            for(int i = 1;i<=min(A,K);i++){
                if(B>=K-i&& (K-i)){
                    ans+=ncr(A,i)*ncr(B,K-i);
                    ans%=mod;
                }
            }
            lli y = ncr(C,c);
            (ans*=y)%=mod;
            cout<<ans<<endl;
        }
    }

    return 0;  
}  

