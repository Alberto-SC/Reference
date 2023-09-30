#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int maxn = 200007;
vector<int> p(maxn);
vector<int> graph[maxn];
pair<int,int> dfs(int v,int parent = -1,int dist= 0){
    p[v] = parent; 
    pair<int,int> vertex = {dist,v};
    for(auto c:graph[v]){
        if(c ==parent)continue;
        vertex = max(vertex,dfs(c,v,dist+1));
    }
    return vertex;
}
int main(){
    int n,a,b;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>a>>b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    
    }
    pair<int,int>A = dfs(0);
    pair<int,int>B = dfs(A.y);
    vector<int>edges;
    // cout<<A.x<<" "<<A.y<<"   "<<B.x<<" "<<B.y<<endl;
    int v = B.y;
    while(v!= A.y){
        edges.push_back(v);
        v = p[v];
    }
    edges.push_back(A.y);
    if(edges.size()==n)cout<<n-1<<endl<<edges[0]+1<<" "<<edges[1]+1<<" "<<edges.back()+1<<endl;
    else{
        queue<int>q;
        vector<int> path(n,-1);
        for(auto c:edges){
            path[c]= 0;
            q.push(c);
        }
        while(!q.empty()){
            int v =q.front();
            q.pop();
            for(auto c: graph[v]){
                if(path[c]== -1){
                    path[c]= path[v]+1;
                    q.push(c);
                }
            }
        }
        pair<int,int> mx = {path[0],0};
        for(int i = 0;i<n;i++)mx = max(mx,{path[i],i});
        cout<<(edges.size()-1)+mx.x<<endl<<edges[0]+1<<" "<<mx.y+1<<" "<<edges.back()+1<<endl;
    }
    return 0;
}