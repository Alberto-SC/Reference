#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100005;
vector<int> graph[maxn];
vector<bool> used(maxn);
vector<int> deep(maxn);
int k;
void dfs1(int u,int p = -1,int d = 0){
    deep[u] = d;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs1(v,u,d+1);
    }
}



signed main(){__
    int n,u,v;
    cin>>n>>k;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> ans;
    ans.push_back(1);
    set<int> poss;
    for(int i = 1;i<n;i++){
        poss.insert(i);
    }

    while(poss.size()){
        bool flag = false;
        int res = -1;
        for(auto c:poss){
            dfs1(c);
            for(auto d:ans){
                if(deep[d-1]<=k){
                    flag = true;
                    res = c;
                    break;
                }
            }
            if(flag)
                break;
        }
        ans.push_back(res+1);
        poss.erase(res);
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
}


