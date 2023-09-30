#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> cost(maxn),c(maxn);
vector<int> graph[maxn];
vector<int> in(maxn);
set<int> st;
void topo(int n){
    queue<int> q;
    for(int i = 0;i<n;i++){
        if(in[i]==0){
            cost[i] = c[i];
            if(st.count(i))cost[i] = 0;
            q.push(i);
        }
    }

    while(q.size()){
        int u = q.front();
        cost[u] = min(cost[u],c[u]);
        if(st.count(u))cost[u] = 0;
        
        q.pop();
        
        for(auto v:graph[u]){
            in[v]--;
            cost[v]+= cost[u];
            if(in[v]==0){
                q.push(v);
            }
            
        }
    }

}

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        
        for(int i = 0;i<n;i++)graph[i].clear(),in[i] = 0,cost[i] = 0;
        st.clear();
        c.resize(n);
        for(auto &x:c)cin>>x;

        for(int i = 0;i<k;i++){
            int x;
            cin>>x;
            x--;
            st.insert(x);
        }

        for(int i = 0;i<n;i++){
            int sz;
            cin>>sz;
            for(int j = 0;j<sz;j++){
                int v; 
                cin>>v;
                v--;
                graph[v].push_back(i);
                in[i]++;
            }
        }

        topo(n);
        for(int i = 0;i<n;i++)cout<<cost[i]<<" ";
        cout<<endl;
    }
    return 0;
}