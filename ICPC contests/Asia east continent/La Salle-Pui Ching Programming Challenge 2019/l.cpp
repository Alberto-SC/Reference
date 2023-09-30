#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long

const int maxn = 1000007;
vector<int> sz(maxn,1);
vector<int> p(maxn);

int raiz(int u){
    return p[u]==u?u:p[u] = raiz(p[u]);
}

void union_by_sz(int a,int b){
    a = raiz(a);
    b = raiz(b);
    if(a==b)return;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b];
    p[b] = a;
}
const int mod = 1e9+7;

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
signed main(){
    int n,r,c;
    cin>>n>>r>>c;
    iota(p.begin(),p.end(),0);
    int node = 0;    
    for(int i = c-1;i>=0;i--){
        for(int j = 0;j<r;j++){
            int x = (j*c)+i;
            union_by_sz(x,node);
            node++;
        }        
    }
    set<int> st;
    for(int i = 0;i<r*c;i++)
        st.insert(raiz(i));
    cout<<bin_pow(n,(int)st.size())<<endl;
}


