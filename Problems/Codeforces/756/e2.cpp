#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxn = 200007;
vector<int> graph[maxn];
vector<int> valid(maxn);
vector<int> s;
const int inf = 1e9;
vector<int> dist(maxn,inf);

void bfs(){
    queue<int> q;
    for(int i = 0;i<s.size();i++){
        q.push(s[i]);
        dist[s[i]] = 0;
    }
    valid[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:graph[u]){
            if(dist[v]>dist[u]+1){
                dist[v] = dist[u]+1;
                valid[v] = valid[u];
                q.push(v);
            }
            else if(dist[v]==dist[u]+1){
                valid[v] = 0;
            }
        }
    }
}
bool flag = false;
int ans = 0;
void dfs(int u,int p = -1){
    int childs = 0;
    for(auto v:graph[u]){
        if(v==p)continue;
        childs++;
        if(valid[v])dfs(v,u);
        else ans++;
    }
    if(childs ==0)flag = true;
}

signed main(){__
    int T = 1,n,k,u,v;
    cin>>T;
    while(T--){
        cin>>n>>k;
        s.clear();
        for(int i = 0;i<n;i++)graph[i].clear(),dist[i] = inf,valid[i] = 0;
        s.push_back(0);
        for(int i = 0;i<k;i++){
            int x;cin>>x;
            x--;
            s.push_back(x);
        }
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs();
        flag = false;
        ans = 0;
        dfs(0);
        // for(int i = 0;i<n;i++){
        //     cout<<dist[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0;i<n;i++)
        //     cout<<valid[i]<<" ";
        // cout<<endl;
        if(flag)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}