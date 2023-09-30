#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int top = 0;
const int maxn =100007; 
set<int> graph[maxn];

int main(){__
	int n,m,k,s,t,u,v;
    cin>>n>>m>>k;
    set<int> ks[k];
    set<int> nodes;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        graph[u].insert(v);
    }
    for(int i = 1;i<=n;i++){
        nodes.insert(i);
        ks[i%k].insert(i);
    }
    cin>>s>>t;
    vector<int> dis[n];
    dis[0].push_back(s);
    nodes.erase(s);
    ks[s%k].erase(s);
    int i;
    bool flag = false;
    if(s ==t)return cout<<0<<endl,0;
    for(i = 1;i<n;i++){
        for(int j = 0;j<dis[i-1].size();j++){
            int v = dis[i-1][j];
            for(auto d:graph[v]){
                if(d==t)flag = true;
                graph[d].erase(v);
                ks[d%k].erase(d);
                if(nodes.count(d)){
                    dis[i].push_back(d);
                    nodes.erase(d);
                }
            }
            for(auto d:ks[v%k]){
                if(d==t)flag = true;   
                if(nodes.count(d)){
                    dis[i].push_back(d);
                    nodes.erase(d);
                } 
            }
            ks[v%k].clear();
        }
        if(flag)break;
    }
    if(!flag)cout<<-1<<endl;
    else 
    cout<<i<<endl;
    return 0;
}  

