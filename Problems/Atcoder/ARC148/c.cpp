#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q,p,m;
    while(T--){
        cin>>n>>q;
        vector<int> parent(n);
        for(int i = 1;i<n;i++){
            cin>>p;
            p--;
            parent[i] = p;
            graph[p].push_back(i);
        }
        dfs(0);
        vector<bool> v(n);
        while(q--){
            cin>>m;
            vector<int> nodes(m);
            
        }
    }
    return 0;
}