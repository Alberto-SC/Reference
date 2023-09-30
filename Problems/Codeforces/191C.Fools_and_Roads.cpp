#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> st;
vector<lli> lazy;

void propagate(lli v,lli l,lli r){
    if(lazy[v]==0)return;
    st[v]+= lazy[v]*((r-l)+1);
    if(l!=r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1] += lazy[v];
    }
    lazy[v] = 0;
}
lli n;
void update(lli l,lli r,lli x,lli v = 1,lli sl = 0,lli sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr || l>r)return;
    if(sl>=l && sr<=r){
        lazy[v]+=x;
        propagate(v,sl,sr);
        return;
    }
    lli m = (sl+sr)>>1;
    update(l,r,x,v<<1,sl,m);
    update(l,r,x,v<<1|1,m+1,sr);
    st[v] =st[v<<1]+st[v<<1|1];
}

lli query(lli l,lli r,lli v = 1,lli sl = 0,lli sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr )return 0;
    if(sl>=l && sr<=r)return st[v];
    lli m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

const lli maxn = 100007;
vector<lli> graph[maxn];
vector<lli> heavy(maxn,-1), sz(maxn),head(maxn),pos(maxn),pr(maxn),lvl(maxn);
void dfs(lli u,lli p = -1,lli d = 0){
    sz[u] = 1;
    pr[u] = p;
    lvl[u] = d;
    lli mx = 0;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u,d+1);
        sz[u]+=sz[v];
        if(sz[v]>mx){
            mx = sz[v];
            heavy[u]= v;
        }
    }
}

void hld(){
    dfs(0);
    lli idx = 0;
    for(lli i = 0;i<n;i++){
        if(pr[i] == -1 || heavy[pr[i]] != i)
			for(int j = i; j != -1; j = heavy[j]){
				head[j] = i;
				pos[j] = idx++;
            }
    }
}

void updateHLD(lli u,lli v,lli val){
    while(head[u]!= head[v]){
        if(lvl[head[u]]<lvl[head[v]])
            swap(u,v);

        update(pos[head[u]],pos[u],val);
        u = pr[head[u]];
    }
    if(lvl[u]>lvl[v])
        swap(u,v);
    update(pos[u]+1,pos[v],val);
}

void print(){
    for(lli i = 0;i<n;i++){
        cout<<query(i,i)<<" ";
    }
    cout<<endl;
}

int main(){
    lli u,v,q;
    cin>>n;
    st.resize(4*n);
    lazy.resize(4*n);
    vector<pair<lli,lli>> edges;
    for(lli i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        edges.push_back({u,v});
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    hld();
    cin>>q;
    for(lli i = 0;i<q;i++){
        cin>>u>>v;
        u--,v--;
        updateHLD(u,v,1);
    }
    for(lli i = 0;i<n-1;i++){
        u = edges[i].first;
        v = edges[i].second;
        if(pr[u]==v){
            query(pos[u],pos[u]);
            cout<<query(pos[u],pos[u])<<" ";
        }
        else{
            query(pos[v],pos[v]);
            cout<<query(pos[v],pos[v])<<" ";
        }

    }
    cout<<endl;
    return 0;
}