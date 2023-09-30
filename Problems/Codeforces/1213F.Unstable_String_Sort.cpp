#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> grapht[maxn];
vector<int> order;
vector<int> components;
vector<bool> vis(maxn);
void dfs(int u){
    vis[u] = true;
    for(auto v:graph[u]){
        if(vis[v])continue;
        dfs(v);
    }
    order.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    components.push_back(u);
    for(auto v:grapht[u]){
        if(vis[v])continue;
        dfs2(v);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    vector<int> q(n);
    string ans = string(n,'z');
    for(auto &c:p)cin>>c;
    for(auto &c:q)cin>>c;
    for(int i = 0;i<n-1;i++){
        graph[p[i]].push_back(p[i+1]);
        graph[q[i]].push_back(q[i+1]);
        grapht[p[i+1]].push_back(p[i]);
        grapht[q[i+1]].push_back(q[i]);
    }
    for(int i = 1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    int cont = 0;
    vector<int> comp(n+1);
    vis.assign(n,false);
    for(int i = 0;i<n;i++){
        int v = order[n-1-i];
        if(!vis[v]){
            dfs2(v);
            for(auto c:components){
                comp[c] = cont;
            }
            cont++;
            components.clear();
        }
    }
    // for(auto c:comp)cout<<c<<" ";
    // cout<<endl;
    if(cont<k)return cout<<"NO"<<endl,0;
    else {
        cout<<"YES"<<endl;
        for(int i = 0;i<n;i++)
            ans[p[i]-1] = char(min(25,comp[p[i]])+'a');
        cout<<ans<<endl;
    }
    
}