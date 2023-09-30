#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
const int maxn = 10007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
vector<int> color(maxn,-1);
vector<pair<int,int>> cycle;
bool flag = false;
void dfs(int u,int p = -1){
    if(u == 0)color[u] = 0;
    else
        color[u] = !color[p];

    for(auto v:graph[u]){
        if(color[v] != -1)
            dfs(v);
        else{
            if(color[v]== color[u]){
                flag = true;
                cycle.push_back({u,v});
                return;
            }
        }
        if(flag)
            cycle.push_back({u,v});
        
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    map<pair<int,int>,int>mp;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        graph[--u].push_back(--v);
        graph[v].push_back(u);
        mp[{u,v}] = i;
    }
    dfs(0);
    for(auto c:cycle){
        cout<<c.x<<" "<<c.y<<endl;
    }
    cout<<endl;
    if(!flag){
        cout<<m<<endl;
        for(int i = 0;i<n;i++)cout<<i+1<<" ";
        cout<<endl;
    }
    else{
        vector<bool> ans(m);
        for(auto v:cycle){
            if(mp.count(v))
                ans[mp[v]] = true;
            else {
                ans[mp[{v.y,v.x}]] = true;
            }
        }
        cout<<cycle.size();
        for(int i = 0;i<m;i++)
            if(ans[i])cout<<i+1<<endl;
    }

    return 0;
}