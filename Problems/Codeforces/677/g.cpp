#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long int lli;
const lli INF = 10e15;
const int MAX = 1440007;
lli D[MAX];
lli P[MAX];
lli N;

vector<pair<int,lli>> graph[MAX]; 
void add_edge(int u,int  v,lli cost){
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}
// dijkstra with priority queue
vector<int> restore_path(int s, int t) {
    vector<int> path;
    for (int v = t; v != s; v = P[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
int n;
void dijkstra(lli s){
    for(int i=0;i<n;i++)D[i] = INF;
    D[s] = 0;
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> q;
    q.push({0,s});
    while(!q.empty()){
        pair<lli,lli> p = q.top();
        q.pop();
        int u = p.y;
        lli dist = p.x;
        if(dist > D[u]) continue;
        for(auto pr: graph[u]){
            int v = pr.x;
            lli next_dist = dist + pr.y;
            if(next_dist < D[v]){
                D[v] = next_dist;
                P[v] = u;
                q.push({next_dist,v});
            }

        }   
    }
}
int main(){
	lli m,u,v,w,k;
	cin>>n>>m>>k;
    map<pair<int,int>,pair<int,int>> mp;
	for(int i = 0;i<m;i++) {
		cin>>u>>v>>w;
		u--;
		v--;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
        mp[{u,v}] = {w,0};
        mp[{v,u}] = {w,0};
    }
    lli ans = 0;
    for(int i = 0;i<k;i++){
        cin>>u>>v;
        u--,v--;
        memset(P,-1,sizeof(P));
        dijkstra(u);
        ans+=D[v];
        vector<int> path = restore_path(u,v);
        for(int i = 0;i<path.size()-1;i++){
           mp[{path[i],path[i+1]}].second++; 
        }
    }
    cout<<"HI"<<endl;
    cout<<ans<<endl;
    lli res = INF;
    for(auto c:mp){
        cout<<c.x.x<<" "<<c.x.y<<" "<<c.y.x<<" "<<c.y.y<<endl;
        res = min(res,ans-(c.y.x*c.y.y));
    }
    cout<<res<<endl;
    
}