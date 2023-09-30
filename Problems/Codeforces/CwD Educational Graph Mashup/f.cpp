#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
int q[maxn];
vector<int> dist(maxn);
vector<int> graph[maxn];
int top = 0;
int n,inf = 1e9;
pair<int,int> bfs(int s){
    top = 0;
    for(int i = 0;i<n;i++)
        dist[i] = inf;
    dist[s] = 0;
    q[top++] = s;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(dist[u]+1>dist[v])continue;
            dist[v] = dist[u]+1;
            q[top++] = v;
        }
    }
    int mxn,mx = 0;
    for(int i = 0;i<n;i++){
        if(dist[i]>mx){
            mx = dist[i];
            mxn = i;
        }
    }
    return {mxn,mx};
}

int main(){__
	int t= 1,a,b,da,db,u,v;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>da>>db;
        for(int i = 0;i<n;i++)graph[i].clear();
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int dim = bfs(bfs(0).first).second; 
        bfs(--a);
        if(dist[--b]<=da)cout<<"Alice"<<endl;
        else if(min(db,dim)>2*da)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}  

