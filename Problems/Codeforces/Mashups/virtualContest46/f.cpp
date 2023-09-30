#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 2007;
vector<int> graph[maxn];
vector<int> sz(maxn);
vector<int> c(maxn);
vector<int> ans(maxn);
bool flag = true;
vector<bool> used(maxn*10,true);
void dfs(int u,int p = -1){
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    if(c[u]>=sz[u])flag = false;
}

void dfs2(int u,int p = -1){
    int l = 0;
    while(!used[l]){
        l++;
    }
    while(c[u]){
        c[u]-=used[l++];
    }
    while(!used[l]){
        l++;
    }
    ans[u] = l;
    used[l] = false;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs2(v,u);
    }

    
}
signed main(){__
    int n,p;
    cin>>n;
    used[0] = false;
    int root = 0;
    for(int i = 0;i<n;i++){
        cin>>p>>c[i];
        if(p==0)root = i;
        else{
            graph[i].push_back(p-1);
            graph[p-1].push_back(i);
        }
    }
    dfs(root);
    if(!flag)cout<<"NO"<<endl;
    else{
        dfs2(root);
        int l = 0;
        cout<<"YES"<<endl;
        for(int i = 0;i<n;i++){
            if(ans[i]==0){
                while(!used[l]){
                    l++;
                }
                ans[i]= l;
                used[l] = false;
            }
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}  
