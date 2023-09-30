#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<pair<int,int>> graph[maxn];

map<int,int> mp1;
map<int,int> mp2;

int a,b;
bool flag;
void dfs(int u,int who = 0,int x = 0,int p = -1){
    if(who==0 && u ==b){
        if(x == 0)flag = true;
        return;
    }
    if(p!=-1){
        if(who)
            mp2[x]++;
        else 
            mp1[x]++;
    }
    for(auto v:graph[u]){
        if(v.first == p)continue;
        dfs(v.first,who,x^v.second,u);
    }
}

signed main(){__
    int T = 1,n,u,v,w;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        for(int i = 0;i<n;i++){
            graph[i].clear();
        }
        mp1.clear();
        mp2.clear();
        for(int i = 0;i<n-1;i++){
            cin>>u>>v>>w;
            u--,v--;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        a--,b--;
        flag = false;
        dfs(a);
        dfs(b,1);
        for(auto c:mp1){
            if(mp2.count(c.first))flag = true;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}