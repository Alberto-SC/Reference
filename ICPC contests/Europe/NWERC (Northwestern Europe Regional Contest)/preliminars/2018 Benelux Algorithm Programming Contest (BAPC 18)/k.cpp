#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> childk(maxn);
vector<int> graph[maxn];
vector<int> subtree[maxn];
int subt = -1;
void dfs(int u,int p =-1){
    if(childk[u])subt = u;
    int cont = 0;
    for(auto v:graph[u]){
        if(v == p)continue;
        cont++;
        dfs(v,u);
    }
    if(cont == 0){
        subtree[subt].push_back(u);
    }
}
int main(){
	int t= 1,n,k,u,v;
    while(t--){
        cin>>n>>k;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(u == k){
                childk[v] = true;
            }
            else if(v == k){
                childk[u] = true;
            }
        }
        dfs(k);
        vector<pair<int,int>> ans;
        int last = 2;
        for(int i= 0;i<graph[k].size()-1;i+=2)
            ans.push_back({subtree[graph[k][i]][0],subtree[graph[k][i+1]][0]});

        if(graph[k].size()&1){
            ans.push_back({subtree[graph[k].back()][0],k});
        }
        
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
        cout<<endl;

    }
    return 0;
}  

