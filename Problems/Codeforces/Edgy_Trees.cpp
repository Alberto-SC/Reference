#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
const lli mod = 1000000007;
#define MOD(n) ( ( ((n) % (mod)) + (mod) ) % (mod))

const int maxn = 100007;
vector<int> padre(maxn);
vector<lli> sz(maxn,1);
int raiz(int v){
    return v== padre[v]?v:padre[v] = raiz(padre[v]);
}
void union_bySize(int u,int v){
    u = raiz(u);
    v = raiz(v);
    if (u != v) {
        if (sz[u] < sz[v])
            swap(u, v);
        padre[v] = u;
        sz[u] += sz[v];
    }  
}

lli pow_mod(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) x = (x*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return x;
}

int main(){
    int n,k,u,v,c;
    cin>>n>>k;
    iota(padre.begin(),padre.end(),0);
    for(int i = 0;i<n-1;i++){
        cin>>u>>v>>c;
        u--,v--;
        if(c == 0)
           union_bySize(u,v);
    }
    lli ans = pow_mod(n,k);
    vector<bool> used(n,false);
    for(int i= 0;i<n;i++){
        if(used[raiz(i)] == false){
            used[raiz(i)] = true;
            ans = MOD(ans- pow_mod(sz[raiz(i)],k));
        }
    }
    cout<<ans<<endl;
    return 0;
}