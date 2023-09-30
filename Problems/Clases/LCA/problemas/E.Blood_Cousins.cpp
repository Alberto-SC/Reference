#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

const int maxn = 200007;
vector<int> depth(maxn);
vector<int> graph[maxn];
int P[25][maxn];

vector<int> levels[maxn];
vector<int> start(maxn);
vector<int> End(maxn);
int id;
void dfs(int u,int p = -1,int d = 0){
    depth[u] = d;
    P[0][u] = p;
    start[u] = id++;
    levels[d].push_back(start[u]);
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u,d+1);
    }
    End[u] = id;
}


void build(int n){
    for(int i = 0;i<25;i++)
        for(int j = 0;j<n;j++)
            P[i][j] = -1;

    for(int i = 0;i<n;i++)
        if(P[0][i]==-1)dfs(i);

    for(int i = 1;i<25;i++)
        for(int u = 0;u<n;u++)
            if(P[i-1][u]!=-1)
                P[i][u] = P[i-1][P[i-1][u]];
}


signed main(){__
    int t = 1,n,q,p,k,u,v;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>p;
        if(p==0)continue;
        p--;
        graph[i].push_back(p);
        graph[p].push_back(i);
    }        

    build(n);
    for(int i = 0;i<n;i++)
        sort(levels[i].begin(),levels[i].end());
    
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>u>>k;
        u--;
        v = u;
        for(int j= 24;j>=0;j--){
            if((k>>j)&1)v = P[j][v];
            if(v==-1)break;
        }
        
        if(v==-1){
            cout<<0<<" ";
            continue;
        }

        int d = depth[u];
        int l = lower_bound(levels[d].begin(),levels[d].end(),start[v])-levels[d].begin();
        int r = upper_bound(levels[d].begin(),levels[d].end(),End[v])-levels[d].begin();

        cout<<(r-l)-1<<" ";
    }
    cout<<endl;
    return 0;
}