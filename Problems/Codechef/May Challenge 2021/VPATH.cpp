#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> dpv(maxn,1);
vector<int> dplca(maxn,0);
const int mod = 1e9+7;

void dfs(int u,int p =-1){
    int sum = 0;
    for(auto v: graph[u]){
        if (v==p)continue;
        dfs(v,u);
        (dpv[u]+=2*dpv[v])%=mod;
        (dplca[u]+=dplca[v])%=mod;
        (sum+=dpv[v])%=mod;
    }
    for(auto v:graph[u]){
        if(v==p)continue;
        int x = sum-dpv[v];
        x%=mod;
        if(x<0)x+=mod;
        (dplca[u]+=dpv[v]*x)%=mod;
    }
}

signed main(){__
	int t= 1,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear(),dplca[i] = 0,dpv[i]= 1; 
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0);
        int ans = (dplca[0]+dpv[0])%mod;
        cout<<ans<<endl;
    }
    return 0;
}  



