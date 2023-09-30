#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> graph[2007];
vector<bool> vis(2007);
bool dfs(int u,int t){  
    vis[u]= true;
    if(u == t)return true;
    for(auto v:graph[u]){
        if(vis[v])continue;
        if(dfs(v,t))return true;
    }
    return false;
}
signed main(){
	int t= 1,n,q,u,v;
    cin>>q;
    for(int i = 1;i<=1000;i++){
        for(int j = i;j<=1000;j++){
            if((i&j) == i)graph[j].push_back(i+j);
        }
    }
    for(int i = 0;i<q;i++){
        cin>>u>>v;
        for(int j=0;j<=1000;j++)
            vis[j] = false;
        if(dfs(u,v))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  