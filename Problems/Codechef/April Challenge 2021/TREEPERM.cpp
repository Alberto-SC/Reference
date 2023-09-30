#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
const int mod = 1e9+7;
vector<int> g[maxn];
vector<int> gt(maxn);

vector<bool> used(maxn);
vector<bool> first(maxn);
vector<int> a(maxn);
vector<int> b(maxn);

int ans;
vector<int> bads[maxn];
signed main(){__
    int t,n,u,v,s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        for(int i = 0;i<n;i++)g[i].clear(),gt[i]= -1,bads[i].clear(),used[i] =false,first[i] =false;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for(int i = 0;i<n;i++)
            cin>>a[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        vector<int> q(2*n);
        vector<int> d(n,1e9);
        int top = 0;
        q[top++] = 0;
        d[0] = 0;
        for(int i = 0;i<top;i++){
            u = q[i];
            for(auto to:g[u]){
                if(d[to]<=d[u]+1)continue;
                gt[to] = u;    
                d[to] = d[u]+1;                
                q[top++] = to;
            }
        }

        for(int i = 0;i<n;i++){
            if(a[i]!=b[i])bads[d[i]].push_back(i);
        }
        bool flag = true;
        bool correct;
        int sum = 0;
        map<int,int> mp;
        for(int i = n-1;i>=0;i--){
            for(auto from:bads[i]){
                if(used[from])continue;
                v = from;
                correct = false;
                first[v] = true;
                while(v!= -1){
                    if(used[v])break; 
                    mp[a[v]]++;
                    if(mp[a[v]]==0)mp.erase(a[v]);
                    mp[b[v]]--;
                    if(mp[b[v]]==0)mp.erase(b[v]);
                    if(mp.size()==0){
                        used[v] = true;
                        correct = true;
                        break;
                    }
                    used[v] = true;
                    v = gt[v];
                }
                flag = correct;
                
                if(!flag)break;
            } 
            if(!flag)break;
        }
        if(!flag)cout<<0<<endl;
        else {
            ans = 1;
            if(s==1)
                cout<<ans<<endl;
            else{
                top = 0;
                q[top++] = 0;
                vector<int> vis (n);
                for(int i = 0;i<top;i++){
                    u = q[i];
                    vis[u] = true;
                    if(!used[u]||first[u]){
                        (ans*=g[u].size()+(i==0?1:0))%=mod;
                    }
                    for(auto to:g[u]){
                        if(vis[to])continue;
                        q[top++] = to;
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
