#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> q(maxn);
vector<int> dist[2];
const int inf = 1e9;
int bfs(int s,int n,int who){
    dist[who].resize(n);
    for(int i = 0;i<n;i++)
        dist[who][i] = inf;
    dist[who][s] = 0;
    int idx = 0;
    q[idx++] = s;
    for(int i = 0;i<idx;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(dist[who][u]+1<dist[who][v]){
                dist[who][v] = dist[who][u]+1;
                q[idx++] = v;
            }
        }
    }
    int mx = 0;
    for(int i = 0;i<n;i++)
        mx = max(mx,dist[who][i]);
    for(int i = 0;i<n;i++)
        if(dist[who][i] == mx)return i;
}
int main(){__
    freopen("awesome.in", "r", stdin);
	int t= 1,n,l,r,u,v;
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        for(int i = 0;i<n;i++){
            graph[i].clear();
        }
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s2 = bfs(bfs(0,n,0),n,0);
        cout<<s2<<endl;
        bfs(s2,n,1);
        // bfs2(s2,n);
        for(int i= 0;i<n;i++)
            cout<<dist[0][i]<<" ";
        cout<<endl;
        for(int i = 0;i<n;i++)
            cout<<dist[1][i]<<" ";
        cout<<endl;
        int ans = 0;
        int mn = (n-1)-r;
        int mx = (n-1)-l;
        cout<<mn<<" "<<mx<<endl;
        vector<int> b(n);
        for(int i = 0;i<n;i++){
            b[max(dist[0][i],dist[1][i])]++;
        }
        for(int i = 1;i<n;i++)
            b[i] = b[i]+b[i-1];
        for(int i = 0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
        for(int i = 0;i<n;i++){
            int distmax = max(dist[0][i],dist[1][i]);
            if(distmax<mn)continue;
            cout<<distmax<<" "<<(min(mx,distmax)-mn)+1<<endl;
            if(mn-1>=0)
                ans+=b[min(mx,distmax)]-b[mn-1]-1;
            else 
                ans+= b[min(mx,distmax)]-1;
            
        }
        cout<<ans/2<<endl;
    }
    return 0;
}  
