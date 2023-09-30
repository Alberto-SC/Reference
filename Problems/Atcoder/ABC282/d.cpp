#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];
vector<int> color(maxn,-1);

bool flag = true;
int c1= 0,c2 = 0;
void dfs(int u,int p = -1){
    if(p == -1)color[u] = 0;
    else color[u] = color[p]^1;
    if(color[u])c2++;
    else c1++;
    for(auto v:graph[u]){
        if(color[v]!=-1 && color[v]== color[u])flag = false;
        if(color[v]!=-1)continue;
        dfs(v,u);
    }
}

signed main(){__
    int T = 1,n,m,u,v;
    while(T--){
        cin>>n>>m;
        
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = 0;
        vector<int> v;
        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                c1 = 0,c2 = 0;
                dfs(i);
                v.push_back(c1+c2);
                ans+=c2*c1;
            }
        }
        int sum = 0;
        for(int i = 0;i<v.size();i++){
            ans+=v[i]*sum;
            sum+=v[i];
        }
        if(!flag)cout<<0<<endl;
        else cout<<ans-m<<endl;

    }
    return 0;
}