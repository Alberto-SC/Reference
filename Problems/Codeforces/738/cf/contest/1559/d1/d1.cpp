#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> sz[2];
vector<int> p[2];

int raiz(int u,int w){
    return u == p[w][u]?u:p[w][u] = raiz(p[w][u],w);
}

bool union_sz(int u,int v,int w){
    u = raiz(u,w);
    v = raiz(v,w);
    if(u==v)return false;
    if(sz[w][u]<sz[w][u])
        swap(u,v);
    sz[w][u]+=sz[w][u];
    p[w][v] = u;
    return true;
}

bool conexo(int u,int v,int w){
    u = raiz(u,w);
    v = raiz(v,w);
    return u==v;
}

signed main(){
	int t= 1,n,m1,m2,u,v;
    cin>>n>>m1>>m2;
    sz[0].resize(n,1);
    sz[1].resize(n,1);
    p[0].resize(n);
    p[1].resize(n);
    iota(p[0].begin(),p[0].end(),0);
    iota(p[1].begin(),p[1].end(),0);
    for(int i = 0;i<m1;i++){
        cin>>u>>v;
        u--,v--;
        union_sz(u,v,0);
    }
    for(int i = 0;i<m2;i++){
        cin>>u>>v;
        u--,v--;
        union_sz(u,v,1);
    }
    for(auto c:p[0])cout<<c<<" ";
    cout<<endl;
    for(auto c:p[1])cout<<c<<" ";
    cout<<endl;
    vector<pair<int,int>> ans;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i==j)continue;
            if(!conexo(i,j,0)&& !conexo(i,j,1)){
                union_sz(i,j,0);
                union_sz(i,j,1);
                ans.push_back({i,j});
            }

        }
    }
    // cout<<ans.size()<<endl;
    // for(auto c:ans)cout<<c.first+1<<" "<<c.second+1<<endl;
    return 0;
}  
