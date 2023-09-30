#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear();
        int root = 0;
        vector<int> parent(n);
        for(int i = 0;i<n;i++){
            cin>>parent[i];
            parent[i]--;
            if(parent[i]==i)root = i;
            else graph[parent[i]].push_back(i);
        }
        vector<int> P(n);
        vector<int> pos(n);
        for(int i = 0;i<n;i++){
            cin>>P[i];
            P[i]--;
            pos[P[i]] = i;
        }
        set<pair<int,int>> st;
        st.insert({0,root});
        vector<int> dist(n,-1);
        dist[root] = 0;
        int last = 0;
        vector<int> ans(n);
        ans[root] = 0;
        int mx = 0;
        while(st.size()){
            int u = st.begin()->second;
            st.erase(st.begin());
            if(u!= root){
                int need = last+1;
                int res = need-dist[parent[u]];
                ans[u] = res;
                dist[u] = dist[parent[u]]+res;
                last = dist[u];
            
            }
            for(auto v:graph[u]){
                st.insert({pos[v],v});
            }
        }
        vector<int> V(n);
        iota(V.begin(),V.end(),0);
        sort(V.begin(),V.end(),[&](int a,int b){
            return dist[a]<dist[b];
        });
        if(V != P)cout<<-1<<endl;
        else{
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}