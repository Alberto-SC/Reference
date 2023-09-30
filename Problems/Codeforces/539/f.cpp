#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int mod = 1000000007;
const int MAXN =1000007;
lli inv[MAXN];
lli fact[MAXN];
lli invfact[MAXN];
lli mod_pow(lli a,lli n){
    lli ans = 1;
    while(n){
        if(n&1)ans = (ans*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return ans;
}
void calc(int m){
    inv[0] = inv[1] = 1;
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    for(int i = 2; i <= m; ++i) {
        inv[i] = (inv[mod % i]* (mod - (mod/i)))%mod;
        fact[i] = (fact[i - 1]* i)%mod;
        invfact[i] = (invfact[i - 1]* inv[i])%mod;
    }
}

//Computes C(N,R) modulo P in O(log(n)) time. if P prime
lli Lucas(lli N,lli R){
	if(R<0||R>N)
		return 0;
	if(R==0||R==N)
		return 1ll;
	if(N>=mod)
		return (1ll*Lucas(N/mod,R/mod)*Lucas(N%mod,R%mod))%mod;
	return (1ll* fact[N]*((invfact[N-R]*invfact[R])%mod))%mod;
}

lli binom(int n, int k) {
    return (1ll*fact[n] * ((invfact[k]*invfact[n - k])%mod))%mod;
}
lli permuta(int n,int k){
    return (1ll*fact[n]* invfact[n-k])%mod;
}
lli cayley(int n ,int k){
    if(n-k-1<0)
        return (1ll*k*mod_pow(n,mod-2))%mod;
    return (1ll*k*mod_pow(n,n-k-1))%mod;
}
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    lli ans = 0;
    calc(max(n,m));
    for(int i = 1;i<n;i++){
        if(i>m)break;
        lli cur = 1,cur2 = 1;
        lli vertex_in_path = permuta(n-2,i-1);
        lli ways_to_form_m = Lucas(m-1,i-1);
        cur = (vertex_in_path*ways_to_form_m)%mod;
        lli Other_edges = mod_pow(m,n-i-1);
        lli Other_trees = cayley(n,i+1);
        cur2 = (Other_edges*Other_trees)%mod;
        // cout<<"Vertex  "<<vertex_in_path<<endl;
        // cout<<"Partition  "<<ways_to_form_m<<endl;
        // cout<<"Other edges  "<<Other_edges<<endl;
        // cout<<"Cayley   "<<Other_trees<<endl;
        // cout<<cur<<" "<<cur2<<endl;
        ans = (ans+((cur*cur2)%mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}