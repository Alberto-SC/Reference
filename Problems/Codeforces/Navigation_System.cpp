#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
#define x first 
#define y second

vector<int> graph[maxn];
vector<int> graph2[maxn];
const int INF = 1000000007;
int D[maxn];
int top;
vector<int> q(maxn);
void bfs(int sr){
    for(int i = 0;i<maxn;i++)D[i] = INF;
    top = 0;
    q[top++] = sr;
    D[sr] = 0;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(D[v]<=D[u]+1)continue;
            D[v] = D[u]+1;
            q[top++] = v;
        }
    }
}  

int main(){
    int n,m,k,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        graph[v].push_back(u);
        graph2[u].push_back(v);
    }
    cin>>k;
    vector<int> path(k);
    for(auto &c:path)cin>>c;
    bfs(path[k-1]);
    int less = 0,mx = 0;
    for(int i = 1;i<k;i++){
        if(D[path[i]]!= D[path[i-1]]-1)
            less++;
        else{
            int cont = 0;
            for(auto c:graph2[path[i-1]])
                if(D[c] == D[path[i]])cont++;
            cont--;
            if(cont)mx++;
        }
    }
    cout<<less<<" "<<mx+less<<endl;
    return 0;
}