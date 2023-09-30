#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 300007;
vector<int> graph[maxn];
const int mod = 1e9+7;
vector<int> val(maxn);

void dfs(int u,int p = -1){
    int c = 0;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u);
        c++;
    }
    if(!c)return;
    vector<int> childrens;
    for(auto v:graph[u]){
        if(v==p)continue;
        childrens.push_back(val[v]);
    }

    sort(childrens.rbegin(),childrens.rend());
    for(int i = 1;i<=c;i++){
        if(__builtin_uaddll_overflow(val[u],childrens[i-1]*i,&val[u])){
            cout<<"OVERFLOW"<<endl;
            return;
        }
    }
}
signed main(){__
	int t= 1,n,u,v,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i = 0;i<n;i++)graph[i].clear(),val[i] = 1;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0);
        cout<<((val[0]%mod)*(x%mod))%mod<<endl;
    }
    return 0;
}  
