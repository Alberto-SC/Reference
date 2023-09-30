#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int MAXN = 200007;
const int inf = 1<<30;
vector<pair<int,int>> graph[MAXN];
vector<int> ans;
int dfs1(int u,int p){
    int ans = 0;
    for(auto c:graph[u]){
        if(c.x== p)continue;
        ans+=c.y;
        ans+=(dfs1(c.x,u));
    }
    return ans;
}
void dfs2(int u,int p){
    for(auto c:graph[u]){
        if(c.x == p)continue;
        if(c.y == 0)
            ans[c.x] = min(1+ans[u],ans[c.x]);
        else 
            ans[c.x] = min(ans[u]-1,ans[c.x]);
        dfs2(c.x,u);
    }
}

int main(){
    int n,u,v;
    cin>>n;
    ans.resize(n,inf);
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back({v,0});
        graph[v].push_back({u,1}); 
    }
    ans[0] = dfs1(0,-1);
    dfs2(0,-1);
    int mn = *min_element(ans.begin(),ans.end());
    cout<<mn<<endl;
    for(int i = 0;i<n;i++){
        if(ans[i] == mn){
            cout<<(i+1)<<" ";
        }
    }
    return 0;
}