#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<set<int>> graph;
signed main(){__
	int t= 1,n,u,v,m,q,x;
    while(t--){
        cin>>n>>m;
        graph.resize(n);
        for(int i = 0; i<m;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        set<int> good;
        for(int i = 0;i<n;i++){
            if(graph[i].lower_bound(i+1)==graph[i].end())
                good.insert(i);
        }
        cin>>q;
        while(q--){
            cin>>x;
            if(x==3)cout<<good.size()<<endl;
            else if(x ==1){
                cin>>u>>v;
                u--,v--;
                if(good.count(u) && v>u)
                    good.erase(u);
                if(good.count(v) && u>v)
                    good.erase(v);
                graph[u].insert(v);
                graph[v].insert(u);
            }
            else {
                cin>>u>>v;
                u--,v--;
                graph[u].erase(v);
                graph[v].erase(u);
                if(graph[u].lower_bound(u+1)==graph[u].end())
                    good.insert(u);
                if(graph[v].lower_bound(v+1)==graph[v].end())
                    good.insert(v);
            }
        }
    }
    return 0;
}  
