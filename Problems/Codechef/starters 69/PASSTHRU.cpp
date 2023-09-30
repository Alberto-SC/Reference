#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second

const int maxn = 500007;
vector<pair<int,int>> graph[maxn];
vector<int> c(maxn);
unordered_map<int,int> c1;
unordered_map<int,int> c2;
vector<int> sz(maxn);
vector<int> ans(maxn);


void dfsSize(int u,int p = -1){
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v.first ==p)continue;
        dfsSize(v.first,u);
        sz[u]+=sz[v.first];
    }
}

int sum = 0;
void add(int x){
    sum-=c[x]*((c1[c[x]]*c2[c[x]])>0);
    c2[c[x]]++;
    c1[c[x]]--;
    sum+=c[x]*((c1[c[x]]*c2[c[x]])>0);
}

void rem(int x){
    sum-=c[x]*((c1[c[x]]*c2[c[x]])>0);
    c2[c[x]]--;
    c1[c[x]]++;
    sum+=c[x]*((c1[c[x]]*c2[c[x]])>0);
}

vector<int> *vec[maxn];
void dfs(int u,int p = -1,int id = -1,int keep = 0){
    int heavy = -1,mx = 0,hid = -1;
    for(auto v:graph[u]){
        if(v.x ==p)continue;
        if(sz[v.x]>mx){
            mx = sz[v.x];
            hid = v.y;
            heavy = v.x;
        }
    }

    for(auto v:graph[u]){
        if(v.x== p || v.x==heavy)continue;
        dfs(v.x,u,v.second,0);
    }

    if(heavy !=-1)
        dfs(heavy,u,hid,1),vec[u] = vec[heavy];
    else 
        vec[u] = new vector<int> ();

    vec[u]->push_back(u);
    add(u);

    for(auto v:graph[u]){
        if(v.x==p ||v.x==heavy)continue;
        for(auto x:*vec[v.x]){
            add(x);
            vec[u]->push_back(x);
        }
    }

    if(id != -1)
        ans[id] = sum; 
    if(keep ==0)
        for(auto v:*vec[u])
            rem(v);
}

signed main(){__
    int T = 1,n,u,v;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0;i<n;i++)
            graph[i].clear();
        
        c.resize(n);
        ans.resize(n-1);
        for(auto &z:c){
            cin>>z;
            c1[z]++;
        }

        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back({v,i});
            graph[v].push_back({u,i});
        }

        dfsSize(0);
        dfs(0);

        for(auto z:c){
            c1[z]--;
        }


        for(auto c:ans)cout<<c<<" ";
        cout<<endl; 
    }
    return 0;
}