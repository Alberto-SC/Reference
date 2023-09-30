#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli INF = 10e17;
vector<pair<int,int>> graph[100000];
vector<int> ans;
int padre[100000];
lli D[100000];
set<pair<lli,int> > s; 
int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i = 0;i<m;i++){ 
        cin>>u>>v>>w;
        u--;
        v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    for(int i = 0;i<n;i++)D[i] = INF;
    D[0] = 0;
    priority_queue<pair<lli,int>,vector<pair<lli,int>>,greater<pair<lli,int>>> q;
    q.push({0,0});
    s.insert(make_pair(D[0],0));
    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        int u = p.second;
        // int u = s.begin()->second;
        // s.erase(s.begin());
        for(auto c:graph[u]){
            int v = c.first;
            int w = c.second +D[0];
            if(w + D[u] < D[v]){
                // s.erase(make_pair(D[v],v));
                D[v] = D[u]+ w;
                padre[v] = u;
                // s.insert(make_pair(D[v],v));
                q.push(make_pair([v],v));
            }
        }
    }
    if(D[n-1] == INF)cout<<-1<<endl;
    else{
        int c = n-1;
        while(c!=-0){
            ans.push_back(c);
            c = padre[c];
        }
        ans.push_back(0);
        for(int i = ans.size()-1;i>=0;i--)
            cout<<ans[i]+1<<" ";
        cout<<endl;
    }
    return 0;
}