#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
vector<int> graph[maxn];
int top;
vector<int> dist(maxn);
vector<int> levels[maxn];
vector<int> q(maxn);

void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int mxdist;
void bfs(int n){
    top = 0;
    for(int i = 0;i<n;i++)dist[i]= -1;
    dist[0] = 0;
    q[top++]= 0;
    mxdist = 0;
    levels[0].push_back(0);
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(dist[v] !=-1)continue;
            q[top++] = v;
            dist[v] = dist[u]+1;
            mxdist = max(mxdist,dist[v]);
            levels[dist[v]].push_back(v);
        }
    }
}

int main(){
    int t,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)levels[i].clear(),graph[i].clear();
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            add_edge(u,v);
        }
        bfs(n);
        int size = 0;
        vector<int> ans;
        for(int i = 0;i<n;i+=2){
            size+=levels[i].size();
            for(auto c:levels[i])ans.push_back(c);            
        }
        if(size<=n/2){
            cout<<size<<endl;
            for(auto c:ans)cout<<c+1<<" ";
            cout<<endl; 
        }
        else{
            cout<<n-size<<endl;
            sort(ans.begin(),ans.end());
            int j = 0;
            for(int i = 0;i<n;i++){
                if(j<ans.size() && i== ans[j]){j++;continue;};
                cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }   
    return 0;
}