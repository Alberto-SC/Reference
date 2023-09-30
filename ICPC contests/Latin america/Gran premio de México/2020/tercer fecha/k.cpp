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
        A--,
        B--,
        C-=c;
        K-=c;
        K-=2;
        if(K<0){
            cout<<0<<endl;
        }
        else{
            lli n = A+B;
            if(A+B<K)cout<<0<<endl;
            else {
                lli z = n-K;
                // cout<<z<<" "<<K<<endl;
                // lli x = ncr(k+1,1);
                lli y = ncr(C+c,c);
                lli x= ((z+1)*y)%mod;
                cout<<x<<endl;
            }
        }
    }

    return 0;  
}  

