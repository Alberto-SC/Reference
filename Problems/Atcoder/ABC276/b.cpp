#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,u,v;
    while(T--){
        cin>>n>>m;
        set<int> graph[n+1];
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        for(int i = 1;i<=n;i++){
            cout<<graph[i].size()<<" ";
            for(auto c:graph[i])cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}