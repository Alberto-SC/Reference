#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define x first
#define y second
const int maxn = 50*51;
vector<pair<int,int>> graph[maxn];

vector<int> D(maxn);
const int INF = 1e15;
void dijkstra(int n){
    for(int i=1;i<n;i++)D[i] = INF;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        int u = p.y;
        int dist = p.x;
        if(dist > D[u]) continue;
        for(auto pr: graph[u]){
            int v = pr.x;
            int next_dist = dist + pr.y;
            if(next_dist < D[v]){
                D[v] = next_dist;
                q.push({next_dist,v});
            }

        }   
    }
}


int dist(pair<int,int> a,pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}
signed main(){__
    int t,n,m,f,s,r,c;
    cin>>n>>m>>f>>s;
    int key = 0;
    map<pair<int,int>,int> mp;
    vector<pair<int,int>> shops;
    mp[{0,0}] = key++;
    mp[{n-1,m-1}] = key++;
    shops.push_back({0,0});
    shops.push_back({n-1,m-1});
    for(int i = 0;i<s;i++){
        cin>>r>>c;
        r--,c--;
        mp[{r,c}] = key++;
        shops.push_back({r,c});
    }

    for(int i = 0;i<s+2;i++){
        for(int j =i+1;j<s+2;j++){
            int d =dist(shops[i],shops[j]);
            if(d<=f){
                graph[mp[shops[i]]].push_back({mp[shops[j]],d});
                graph[mp[shops[j]]].push_back({mp[shops[i]],d});
            }
        }
    }
    dijkstra(shops.size());
    cout<<D[1]<<endl;
}   