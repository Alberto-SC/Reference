#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int maxn = 1000007;
vector<int> graph[maxn];


vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,+1,-1};

map<pair<int,int>,int> mp;
map<pair<int,int>,bool> vis;
map<pair<int,int>,int> key;

void bfs(int x,int y){
    cout<<x<<" "<<y<<endl;
    for(int i = 0;i<4;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];   
        if(mp[{nx,ny}] && !vis[{nx,ny}]){
            vis[{nx,ny}] = true;
            graph[key[{nx,ny}]].push_back(key[{x,y}]);
            graph[key[{x,y}]].push_back(key[{nx,ny}]);
            bfs(nx,ny);
        }
    }
}

vector<int> sz(maxn);
void dfs(int u,int p = -1){
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v!= p){
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
}

signed main(){__
    int k = 0,n,x,y,a,b;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        if(i==0)a = x,b = y;
        mp[{x,y}]++;
        vis[{x,y}] = false;
        key[{x,y}] =k++;
    }
    cout<<endl<<endl;
    bfs(a,b);
    dfs(0);
    for(int i = 0;i<k;i++){
        cout<<"I: "<<i<<" -> ";
        for(auto c:graph[i])cout<<c<<" ";
        cout<<endl;
    }
    for(int i = 0;i<k;i++){
        cout<<sz[i]<<" ";
    }
    cout<<endl;
    return 0;
}