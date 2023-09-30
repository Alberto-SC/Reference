#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli n ;
const lli maxn = 100007;
vector<pair<lli,lli>>st;
lli ans;
vector<lli> leaves;
vector<lli> pos;
vector<lli> costos;
vector<pair<lli,lli>> graph[maxn];
pair<lli,lli>  query(lli l,lli r, lli v = 1,lli sl = 0,lli sr = n-1){
    if(r<sl || l>sr|| sl>sr)return {-1,0};
    if(sl>=l && sr<=r)return st[v];
    lli m = (sl+sr)/2;
    return max(query(l,r,v<<1,sl,m),
    query(l,r,v<<1|1,m+1,sr));
}
void update(lli pos,lli val,lli idx,lli v = 1,lli sl = 0,lli sr = n-1){
    if(sl == sr)st[v] = {val,idx};
    else{
        lli m = (sl+sr)/2;
        if(pos<=m)
            update(pos,val,idx,v<<1,sl,m);
        else    
            update(pos,val,idx,v<<1|1,m+1,sr);
        st[v] = max(st[v*2],st[(v*2)+1]);
    }
}

void add_edge(lli u,lli v,lli c){
    graph[u].push_back({v,c});
    graph[v].push_back({u,c});
}

void dfs(lli u,lli &idx,lli p = -1,lli dist = 0,lli cost = 0){
    lli cont = 0;
    pos[u] = idx;
    costos[idx] = cost;
    for(auto v:graph[u]){
        if(v.x == p)continue;
        dfs(v.x,++idx,u,dist+v.y,v.y);
        cont++;
        leaves[u] += leaves[v.x];
    }
    if(!cont)ans+= dist,leaves[u] = 1;
}

int main(){__
    lli t,u,v,c,s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        st.assign(4*n,{0,0});
        pos.assign(n,0);
        leaves.assign(n,0);
        costos.assign(n,0);
        for(lli i = 0;i<n;i++)graph[i].clear();
        for(lli i = 0;i<n-1;i++){
            cin>>u>>v>>c;
            u--,v--;
            add_edge(u,v,c);
        }
        lli idx = 0;
        ans = 0ll;
        dfs(0,idx);
        for(lli i = 0;i<n;i++){
            costos[pos[i]]*=leaves[pos[i]];
        }
        lli cont = 0;
        for(lli i = 0;i<n;i++)
            update(i,costos[i],i);
        cout<<ans<<endl;
        while(ans>s){
            auto mx = query(0,n-1);
            lli diff = mx.x/2ll;
            ans-=(mx.x-diff);
            cont++;
            update(mx.y,mx.x/2ll,mx.y);
        }
        cout<<cont<<endl;
        // cout<<ans<<endl;
    }
    return 0;
}