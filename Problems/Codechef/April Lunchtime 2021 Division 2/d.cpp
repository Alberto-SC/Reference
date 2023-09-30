#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];
vector<int> special(maxn);
vector<int> d1(maxn,-1);
vector<int> dist(maxn);
int parent[25][maxn];
void dfs(int u,int p =-1,int d = 0){
    dist[u] = d;
    parent[0][u] = p;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
        if(d1[v]!=-1)d1[u] = d1[v];
    }
    if(special[u])d1[u] = u;
}

signed main(){__
	int t= 1,n,u,v,k,a,x;
    cin>>t;
    while(t--){
        cin>>n>>k>>a;
        for(int i = 0;i<n;i++){
            graph[i].clear(),special[i] = false,d1[i] = -1,dist[i] = 0;
            for(int j = 0;j<25;j++)
                parent[j][i] =-1;
        }
        for(int i = 0;i<k;i++){
            cin>>x;
            x--;
            special[x] = true;
        }
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        a--;
        dfs(a);
        for(int i = 1;i<25;i++){
            for(int u = 0;u<n;u++){
                if(parent[i-1][u]!= -1)
                    parent[i][u] = parent[i-1][parent[i-1][u]];
            }
        }

        vector<int> ans1(n);
        vector<int> ans2(n);
        for(int i = 0;i<n;i++){
            int v = i;
            if(d1[i]!=-1){
                ans1[i] = dist[i];
                ans2[i] = d1[i];
                continue;
            }
            v = i;
            for(int j = 24;j>=0;j--){
                if(parent[j][v]==-1)continue;
                if(d1[parent[j][v]]==-1){
                    v = parent[j][v];
                }
            }
            ans1[i] = (2*dist[parent[0][v]])-dist[i];
            ans2[i] = d1[parent[0][v]];
        }
        for(auto c:ans1)cout<<c<<" ";
        cout<<endl;
        for(auto c:ans2)cout<<c+1<<" ";
        cout<<endl;
    }
    return 0;
}  
