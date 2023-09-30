#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> D(maxn);
vector<int> parent(maxn);
vector<int> q(maxn*10);
int top = 0;
const int INF = 1e15;

void bfs(int s,int n){
    for(int i=0;i<n;i++)D[i] = INF;
    top = 0;
    D[s] = 0;
    q[top++] = s;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(D[v]>D[u]+1){
                parent[v] = u;
                D[v] = D[u]+1;
                q[top++] = v;
            }
        }
    }

}


signed main(){__
    int t,n,s,T,u,v,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cin>>s>>T;
        for(int i = 0;i<n;i++){
            graph[i].clear();
        }
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs(s,n);
        int u = T;
        vector<int> path;
        while(u!= s){
            path.push_back(u);
            u = parent[u];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        int ans = 0;
        for(int i= 1;i<path.size();i++){
            set<int> st;
            for(auto v:graph[path[i-1]]){
                st.insert(v);
            }

            for(auto v:graph[path[i]]){
                if(st.count(v))
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}   