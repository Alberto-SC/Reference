#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second

const int maxn = 100007;
vector<pair<int,int>> graph[maxn];
vector<int> leafs;
int id;
void dfs(int u,int p =-1,int d = 1,int val = 0){
    int c = 0;
    for(auto v:graph[u]){
        if(v.x==p)continue;
        c++;
        dfs(v.x,u,d+1,val+d*v.y);
    }
    if(c==0)leafs.push_back(val);
}
signed main(){__
	int t= 1,n,u,v,k,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)graph[i].clear();
        vector<int> E(m);
        for(auto &c:E)cin>>c;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v>>k;
            u--,v--;
            graph[u].push_back({v,k});
            graph[v].push_back({u,k});
        }
        leafs.clear();
        dfs(0);
        sort(leafs.begin(),leafs.end());
        sort(E.begin(),E.end());
        int l = 0;
        int ans = 0;
        for(int i = 0;i<leafs.size();i++){
            while(l<m && E[l]<leafs[i]){
                l++;
            }
            if(l==m)break;
            ans++;
            l++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
