#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli maxn = 10007;
vector<lli> p(maxn),sz(maxn);

lli root(lli u){
    return p[u]==u?u:p[u] = root(p[u]);
}

bool un(lli u,lli v){
    u = root(u);
    v = root(v);
    if(u == v)return false;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;   
    return true;
}

struct edges{
    lli u,v,c;
    bool operator <(const edges b){
        return c<b.c;
    }
};

vector<edges> E;
vector<bool> used(500000);


bool check(lli m,lli n){
    iota(p.begin(),p.end(),0);
    sz.assign(n+1,1);
    used.assign(E.size(),false);
    lli cont = 0;
    for(lli i = 0;i<E.size();i++){
        if(E[i].c<m)continue;
        if(un(E[i].u,E[i].v)){
            used[i] = true;
            cont++;
        }
    }
    if(cont == n-1)return true;
    return false;
}

int un2(int u,int v){
    u = root(u);
    v = root(v);
    if(u==v)return 0;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    return (sz[u]-sz[v])*sz[v];
}

int main(){__
	lli t= 1,n,m,u,v,c;
    cin>>n>>m;
    lli mx = 0;
    for(lli i = 0;i<m;i++){
        cin>>u>>v>>c;
        mx = max(mx,c);
        E.push_back({u,v,c});
    }
    lli l = 0,r = mx;
    sort(E.begin(),E.end());
    
    while(l+1<r){
        lli m = (l+r)>>1;
        if(check(m,n))
            l = m;
        else 
            r = m;
    }
    check(l,n);
    iota(p.begin(),p.end(),0);
    sz.assign(n,1);
    // cout<<l<<" "<<r<<endl;
    vector<edges> E2;
    for(lli i = 0;i<E.size();i++)
        if(used[i])
            E2.push_back(E[i]);
    lli ans = 0;
    for(int i = E2.size()-1;i>=0;i--)
        ans+= un2(E2[i].u,E2[i].v)*E2[i].c;
    
    cout<<ans<<endl;
    return 0;
}  

