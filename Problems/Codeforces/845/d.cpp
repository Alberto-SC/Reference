#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> childs[maxn];
vector<int> parent(maxn);
vector<int> out(maxn);
void dfs(int u,int p = -1){
    parent[u] = p;
    for(auto v:graph[u]){
        if (v ==p)continue;
        out[u]++;
        childs[u].push_back(v);
        dfs(v,u);
    }
}

const int mod = 1e9+7;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T = 1,n,u,v;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear();
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0);
        queue<int> q;
        vector<int> ac(n,mod_pow(2,n-1));
        for(int i= 0;i<n;i++){
            if(out[i]==0){
                q.push(parent[i]);
            }
        }
        vector<int> vis(n);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(vis[u])continue;
            vis[u] = true;
            int sum = 0;
            for(auto c:childs[u]){
                sum+=ac[c];
                sum%=mod;
            }
            cout<<u<<" "<<childs[u].size()-2<<endl;
            if(childs[u].size()==1){
                ac[u] += sum;
                ac[u]%=mod;
            }
            else{
                ac[u] += (mod_pow(2,childs[u].size()-2)*sum)%mod;
                ac[u]%=mod;
            }
            if(parent[u]!=-1)
                q.push(parent[u]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans+=ac[i];
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}