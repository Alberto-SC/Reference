#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<set<int>> g(maxn);

bool dir = true;
bool hasCycle(int n){
    vector<int> color(n);
    function<bool(int, int)> dfs = [&](int u, int parent){
        color[u] = 1;
        bool ans = false;
        int ret = 0;
        for(auto v : g[u]){
            if(color[v] == 0)
                ans |= dfs(v, u);
            else if(color[v] == 1 && (dir || v != parent||ret++))
                ans = true;
        }
        color[u] = 2;
        return ans;
    };
    for(int u = 0; u <n; ++u)
        if(color[u] == 0 && dfs(u, -1))
            return true;
    return false;
}

  
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        g[u].insert(v);
        if(g[v].find(u)!=g[v].end())return cout<<-1<<endl,0;
    }
    string s;
    int cont = 0;
    if(hasCycle(n))return cout<<-1<<endl,0;
    for(int i = 1;i<=n;i++){
        if(g[i].size()== 0)s+="E";
        else s+="A",cont++;
    }
    cout<<cont<<endl<<s<<endl;
    return 0;
}