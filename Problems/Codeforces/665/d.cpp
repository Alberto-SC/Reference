#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
const lli maxn = 100007;
const lli mod =  1e9+7;
vector<pair<lli,lli>> graph[maxn];
vector<lli> sz(maxn);
map<pair<lli,lli>,lli> paths;
void add_edge(lli u,lli v,lli cost){
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}
lli N ;
void dfs(lli u,lli p = -1){
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v.x == p)continue;
        dfs(v.x,u);
        sz[u]+=sz[v.x];
    }
    paths[{u,p}] = (N - sz[u])*sz[u];
}
bool comp(pair<pair<lli,lli>,lli> A, pair<pair<lli,lli>,lli> B){
    return A.y>B.y;
}  
int main(){__
    lli t,n,u,v,m;
    cin>>t;
    while(t--){
        cin>>n;
        N =n;
        for(lli i = 0;i<n;i++)graph[i].clear();
        paths.clear();
        for(lli i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            add_edge(u,v,1);
        }
        cin>>m;
        vector<lli> facts(m);
        for(auto &c:facts)cin>>c;
        sort(facts.rbegin(),facts.rend());
        if(m >n-1){
            vector<lli> nfact(n-1);
            nfact[0] = facts[0];
            for(int i = 1;i<(m-(n-2));i++){
                nfact[0] *= facts[i];
                nfact[0]%=mod;
            }
            for(int i = m-(n-2), j = 1;i<m&& j<n-1;i++,j++)
                nfact[j] = facts[i];
            facts = nfact;
        }
        dfs(0);
        // for(auto c:facts)cout<<c<<" ";
        // cout<<endl;
        // for(lli i = 0;i<n;i++)cout<<sz[i]<<" ";
        // cout<<endl;
        vector<pair<pair<lli,lli>,lli>> edges(n);  
        lli k = 0;
        for(auto c:paths){
            // cout<<c.x.x<<" "<<c.x.y<<" -> "<<c.y<k<endl;
            if(k)
                edges[k] =c;
            k++;
        }
        sort(edges.begin(),edges.end(),comp);
        lli ans = 0;
        for(lli i = 0;i<n-1;i++){
            if(i<facts.size()){
                lli z = (((edges[i].y%mod)* (facts[i]%mod))%mod);
                ans  = ((ans%mod)+ (z%mod))%mod;
            }
            else{
                ans= ((ans%mod)+(edges[i].y%mod))%mod;
            } 
            // cout<<edges[i].x.x<<" "<<edges[i].x.y<<" -> "<<edges[i].y<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

