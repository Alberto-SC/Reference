#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxn = 200007;
vector<int> p(maxn);
vector<int> sz(maxn);
int root(int v){
    return v== p[v]?v:p[v] = root(p[v]);
}
void union_bySize(int u,int v){
    u = root(u);
    v = root(v);
    if (u != v) {
        if (sz[u] < sz[v])
            swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
    }  
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        p.assign(n,0);
        sz.assign(n,1);
        iota(p.begin(),p.end(),0);
        for(auto &c:nums)cin>>c,c--;
        vector<int> pos(n);
        for(int i = 0;i<n;i++){
            pos[nums[i]] = i;
        }
        int res = 0;
        vector<bool> vis(n,false);
        for (int i = 0; i < n; i++) {
            if(vis[nums[i]])continue;
            int sz = 1;
            int u = nums[i];
            vis[u] = true;
            int last = u;
            u = nums[u];
            while(!vis[u]){
                union_bySize(u,last);
                last = u;
                vis[u] = true;
                u = nums[u];
                sz++;
            }
            res+=sz-1;
        }
        int ans = 1e9;
        for(int i = 0;i<n-1;i++){
            if(root(i) == root(i+1)){
                ans = min(ans,res-1);
                break;
            }
            else {
                ans = min(ans,res+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}