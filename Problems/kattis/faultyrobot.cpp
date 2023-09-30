#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
vector<pair<int,int>> graph[maxn];
vector<int> dis(maxn);
const int INF = 1e9;
vector<int> q(maxn*1000);
int top = 0;

void bfs(int s){
    for(int i = 0;i<maxn;i++)
        dis[i] =INF;
    dis[s] = 0;
    q[top++] = s;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(int j = 0;j<graph[u].size();j++){
            int v = graph[u][j].first;
            if(dis[v]<dis[u]+graph[u][j].second)continue;
            dis[v] = dis[u]+graph[u][j].second;
            q[top++] = v;
        }
    }
}

int main(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i= 0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        if(a<0)graph[-a].push_back({b,0});
        else graph[a].push_back({b,1});
    }
    vector<int> pos;
    for(int i = 0;i<n;i++){
        int count = 0;
        for(int j = 0;j<graph[i].size();j++){
            count +=graph[i][j].second;
        }
        if(count==graph[i].size())
            pos.push_back(i);
    }
    bfs(0);
    //for(int i = 0;i<n;i++)
        //cout<<dis[i]<<" ";
    //cout<<endl;
    int ans = 0;
    for(int i = 0;i<pos.size();i++)
        if(dis[pos[i]]<=1)ans++;
    cout<<ans<<endl;
    return 0;
}
