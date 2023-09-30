#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
const int maxn = 100007;
vector<pair<int,int>> graph[maxn];

vector<int> c(maxn);
vector<int> c1(maxn);
vector<int> c2(maxn);
vector<int> ans(maxn);
vector<int> sz(maxn);

void dfs_sz(int u,int p = -1){
    sz[u] =1 ;
    for(auto v:graph[u]){
        if(v.x ==p)continue;
        dfs_sz(v.x,u);
        sz[u]+=sz[v.x];
    }
}

int sum = 0;
void add(int x){
    sum-=(c1[c[x]]*c2[c[x]]);
    c2[c[x]]++;
    c1[c[x]]--;
    sum+=(c1[c[x]]*c2[c[x]]);
}

void rem(int x){
    sum-=(c1[c[x]]*c2[c[x]]);
    c2[c[x]]--;
    c1[c[x]]++;
    sum+=(c1[c[x]]*c2[c[x]]);
}

vector<int> *vec[maxn];
void dfs(int u ,int p = -1,int id = -1,int keep = 1){
    int mx = -1,heavy = -1,hid = -1;
    for(auto v:graph[u]){
        if(v.x == p)continue;
        if(sz[v.x]>mx){
            mx = mx;
            hid = v.y;
            heavy = v.x;
        }
    }

    for(auto v:graph[u]){
        if(v.x ==p || v.x == heavy)continue;
        dfs(v.x,u,v.second,0);
    }

    if(heavy!= -1)
        dfs(heavy,u,hid,1),vec[u] = vec[heavy];
    else 
        vec[u] = new vector<int> ();
    vec[u]->push_back(u);
    add(u);
    for(auto v:graph[u]){
        if(v.x ==p || v.x ==heavy)continue; 
        for(auto x:*vec[v.x]){
            add(x);
            vec[u]->push_back(x);
        }
    }
    if(id !=-1)
        ans[id] = sum;
    if(keep ==0)
        for(auto v:*vec[u])
            rem(v);
}

signed main(){__
    int T = 1,n,u,v;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>c[i];
        c1[c[i]]++;
    }

    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }
    dfs_sz(0);
    dfs(0);
    for(int i = 0;i<n-1;i++)
        cout<<ans[i]<<" ";  
    
    cout<<endl;
    return 0;
}