#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100007;
int n,m,p;
#define NIL 0
#define INF (1<<28)
vector<int> G[MAXN];
vector<int> match(MAXN,0);
vector<int> dist(MAXN,0);
bool bfs(){
    int i,u,v,len;
    queue<int>Q;
    for(i =1;i<=n;i++){
        if(match[i] == NIL){
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        if(u!=NIL){
            for(auto v: G[u]){
                if(dist[match[v]] ==INF){
                    dist[match[v]] = dist[u]+1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!= INF);
}
bool dfs(int u){
    int i,v,len;
    if(u!=NIL){ 
        for(auto v:G[u]){
            if(dist[match[v]] == dist[u]+1){
                if(dfs(match[v])){
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
int hopcroft_karp(){
    int matching = 0,i;
    while(bfs())
        for(i = 1;i<=n;i++)
            if(match[i] == NIL && dfs(i))
                matching++;
    return matching;
}
int main(){
    int a,b;
    cin>>n>>m>>p;
    for(int i = 0;i<p;i++){
        cin>>a>>b;
        b+=n;
        G[a].push_back(b);
    }
    cout<<hopcroft_karp();
    return 0;
}