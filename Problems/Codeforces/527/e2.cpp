#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
const int maxn = 1007;
const int inf = 1000000007;
vector<int> graph[maxn];
void add_edge(int u ,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

pair<int,int> dim;
vector<bool> vis(maxn,false);
int mx = 0;

int bfs(int v,int dist[maxn]){
    queue<int> q;
    q.push(v);
    int last;
    dist[v] = 0;
    vector<bool> used(maxn,false);
    used[v] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        last = u;
        for(auto c:graph[u]){
            if(!used[c]){
                dist[c] = dist[u]+1;
                q.push(c);
                used[c] = true;
            }
        }
    }
    return last;
}
vector<int> component;
void dfs(int v,int p){
    vis[v] = true;
    component.push_back(v);
    for(auto c:graph[v]){
        if(c == p)continue;
        dfs(c,v);
    }
}

bool comp(pair<pair<int,int>,int> A ,pair<pair<int,int>,int> B){
    return max(A.first.first,A.first.second)>max(B.first.first,B.first.second);

}

int distx[maxn], disty[maxn];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    vector<int> middle(n-1-m);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    vector<pair<int,int>> nodes;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            component.clear();
            dfs(i,i);
            int x = bfs(i,distx);
            int y = bfs(x,disty);
            for(auto x:component)distx[x] = 0;
            bfs(y,distx);
            int d = disty[y],middlepath;
            for(auto v:component)
                if(distx[v] == d/2 && disty[v] == d- d/2)
                    middlepath = v;
            nodes.push_back({d,middlepath});
        }
    }   
    int center;
    sort(nodes.rbegin(),nodes.rend());
    center = nodes[0].second;
    if(nodes.size()==1)return cout<<nodes[0].first<<endl,0;
    int d = nodes[0].first,d2 = nodes[1].first;
    // for(auto c: nodes)cout<<c.first<<" "<<c.second<<endl;
    if(d == 0 && nodes.size()>2)cout<<2<<endl;
    else if(d == 0 && nodes.size()== 2)cout<<1<<endl;
    else 
        cout<<max(d,(d2-(d2/2))+1+(d-(d/2)))<<endl;
    for(int i = 0;i<(n-1)-m;i++){
        cout<<center+1<<" "<<nodes[i+1].second+1<<endl;
    }
    
    return 0;
}