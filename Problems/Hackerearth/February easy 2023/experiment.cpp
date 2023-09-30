#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n,m,q;

bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>=n || y>=m)return false;
    return true;
}

int F(int x,int y){
    return (x*m)+y;
}
const int maxn = 1000007;
vector<int> parent(maxn);
vector<int> sz(maxn,1);

int root(int u){
    return parent[u]==u?u:parent[u] = root(parent[u]);
}

int ans = 0;
void union_by_size(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return ;
    ans--;
    if(sz[u]<sz[u])swap(u,v);
    sz[u]+=sz[v];
    parent[v] = u;
}

vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,-1,+1};
signed main(){__
    int x,y,t;
    cin>>n>>m>>q;
    iota(parent.begin(),parent.end(),0);
    vector<vector<int>> M(n,vector<int> (m));

    while(q--){
        cin>>t;
        if(t == 1){
            cin>>x>>y;
            x--,y--;
            if(M[x][y]==0)ans++;
            M[x][y] = 1;
            for(int i = 0;i<4;i++){
                int nx = x+fx[i];
                int ny = y+fy[i];
                if(valid(nx,ny) && M[nx][ny]){
                    union_by_size(F(nx,ny),F(x,y));
                }
            }
        }
        else{
            cout<<ans<<endl;
       }
    }
    return 0;
}