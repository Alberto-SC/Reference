#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;
const int maxn = 100007;

vector<pair<int,int>> graph[maxn];
vector<int> pref(maxn);
const int N = (1<<20)+7;
vector<int> mp(N,-1);

int a = -1,b = -1;
void dfs(int u,int p = -1,int x = 0){
    pref[u] = x;
    if(mp[x]!=-1){
        a = mp[x];
        b = u;
    }
    mp[x] = u;

    for(auto v:graph[u]){
        if(v.first ==p)continue;
        dfs(v.first,u,x^v.second);
    }
}

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        mp.assign(N,-1);
        for(int i = 0;i<n;i++)graph[i].clear();
        for(int i = 0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        a = -1,b = -1;
        dfs(0);



        if(a !=-1){
            cout<<1<<" "<<a+1<<" "<<1<<" "<<b+1<<endl;
            continue;
        }
        vector<pair<int,int>> V(N,{-1,-1});
        bool flag = false;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int dist = pref[i]^pref[j];
                if(V[dist].first!=-1){
                    cout<<V[dist].first+1<<" "<<V[dist].second+1<<" "<<i+1<<" "<<j+1<<endl;
                    flag = true;
                    break;
                }
                V[dist] = {i,j};
            }
            if(flag)break;
        }
        if(!flag)cout<<-1<<endl;
    }
    return 0;
}
