#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> value(maxn);
vector<int> depth(maxn);
void dfs1(int u,int p = -1,int h = 0){
    depth[u] = h;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs1(v,u,h+1);
        depth[u] = max(depth[u],depth[v]);
    }
}
void dfs(int u,multiset<int> st,int p = -1){
    int cont = 0;
    sort(graph[u].begin(),graph[u].end(),[&](int a,int b){
        return depth[a]>depth[b];
    });
    vector<int> vmx;
    for(auto v:graph[u]){
        if(v==p)continue;
        int mx = *(st.rbegin());
        st.erase(st.find(mx));
        vmx.push_back(mx);
    }
    int i = 0;
    for(auto v:graph[u]){
        if(v==p)continue;
        st.insert(vmx[i]);
        dfs(v,st,u);
        cont++;
        st.erase(st.find(vmx[i]));
        i++;
    }
    if(!cont)value[u] = *st.rbegin();
}

vector<int> win(maxn);
int ans = 0;
void dfs2(int u,int p = -1){
    int mx = -1;
    int cont = 0;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs2(v,u);
        cont++;
        ans+= win[v];
        mx = max(mx,win[v]);
    }
    if(!cont)win[u] = value[u];
    else 
        win[u] = mx;
}
signed main(){__
	int t= 1,n,p,k;
    while(t--){
        cin>>n>>k;
        vector<int> players(k);
        multiset<int> st;
        for(auto &c:players)cin>>c,st.insert(c); 
        for(int i = 1;i<n;i++){
            cin>>p;
            graph[i].push_back(p);
            graph[p].push_back(i);
        }
        dfs1(0);
        dfs(0,st);
        for(int i = 0;i<n;i++)cout<<value[i]<<" ";
        cout<<endl;
        dfs2(0);
        cout<<ans<<endl;
    }
    return 0;
}  
