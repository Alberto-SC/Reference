#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;

struct E{
    int v,a,b;
};
vector<E> graph[maxn];

vector<int> pref(maxn);
vector<int> ans(maxn);

void dfs(int u,int p = -1,int d = 0,int sum = 0,int val = 0){
    if(p==-1)pref[d] = 0;
    else pref[d] = pref[d-1]+val;
    int l = 0,r = d+1;
    while(l+1<r){
        int m = (l+r)>>1;
        if(pref[m]<=sum)
            l = m;
        else 
            r = m;
    }
    ans[u] = l;
    for(auto v:graph[u]){
        if(v.v == p)continue;
        dfs(v.v,u,d+1,sum+v.a,v.b);
    }
}

signed main(){__
	int t= 1,n,p,a,b;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)
            graph[i].clear();
        
        for(int i = 1;i<=n-1;i++){
            cin>>p>>a>>b;
            p--;
            graph[p].push_back({i,a,b});
        }
        dfs(0);
        for(int i = 1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  
