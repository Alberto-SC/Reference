#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

const int maxn = 400007;
vector<int> graph[maxn];

vector<bool> vis(maxn);
void dfs(int u){
    vis[u] = true;
    for(auto v:graph[u]){
        if(vis[v])continue;
        dfs(v);
    }
}

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> posa(n+1);
        vector<int> posb(n+1);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        for(int i = 0;i<n;i++){
            posa[a[i]] = i;
            posb[b[i]] = i;
            graph[i].clear();
        }
        int cont = 0;
        for(int i = 0;i<n;i++){
            graph[i].push_back(posb[a[i]]);
        }
        vis.assign(n,false);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                cont++;
            }
        }
        
        cout<<bin_pow(2,cont)<<endl;

    }
    return 0;
}  
