#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int need = 0;
int M;
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> mxd(maxn);
void dfs(int u,int d = 0,int ac = 0){
    bool flag = false;
    if(mxd[u]-ac<=M)return ;
    if((mxd[u]-ac-d)+1<=M ){
        need++;
        flag = true;
    }
    else if(d ==M+1){
        need++;
        flag = true;
    }
    
    for(auto v:graph[u]){
        dfs(v, flag ? 2:d+1,ac+flag?d-1:0);
    }
}

void dfs1(int u,int d = 0){
    mxd[u] = d;
    for(auto v:graph[u]){
        dfs1(v,d+1);
        mxd[u] = max(mxd[u],mxd[v]);
    }
}

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i = 0;i<n;i++)mxd[i] = 0,graph[i].clear();
        for(int i= 0;i<n-1;i++){
            int p;cin>>p;
            p--;
            graph[p].push_back(i+1);
        }
        dfs1(0);
        int l = 0, r = n;
        while(l+1<r){
            M = (l+r)>>1;
            need = 0;
            dfs(0);
            if(need<=k) r = M;
            else l = M;
        
        }
        cout<<r<<endl;
    }

    return 0;
}