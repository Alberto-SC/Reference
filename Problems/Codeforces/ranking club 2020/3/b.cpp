#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
#define x first 
#define y second
#define endl '\n'
map<int,int> mp;
vector<int> graph[maxn];
vector<int> st;
vector<int> lazy;
vector<pair<int,int>> ranges(maxn);
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int u,int &idx,int p = -1){
    ranges[u].x = idx;
    mp[u] = idx;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,++idx,u);
    }
    ranges[u].y = idx;
}

void build(int v,vector<int> &A,int l,int r){
    if(l == r)st[v] = A[l];
    else{
        int m = (l+r)>>1;
        build(v*2,A,l,m);
        build(v*2+1,A,m+1,r);
        st[v] = st[v*2] +st[v*2+1];
    }
}

void propagate(int v,int l ,int r){
    if(lazy[v] == 0)return;
    st[v] = ((r-l)+1) - st[v];
    // cout<<st[v]<<endl;
    if(l != r){
        lazy[v*2] ^=1;
        lazy[v*2+1] ^=1;
    }
    lazy[v]^=1;
}
void update(int v,int sl,int sr,int l,int r){
    propagate(v,sl,sr);
    if(l>sr || r <sl)return;
    if(sl>= l && sr<= r){
        lazy[v]^=1;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    update(v*2,sl,m,l,r);
    update(v*2+1,m+1,sr,l,r);
    st[v] = st[v*2]+st[v*2+1];
}


int query(int v ,int sl ,int sr,int l,int r){
    propagate(v,sl,sr);
    if(l>sr || r <sl || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(v*2,sl,m,l,r)+query(v*2+1,m+1,sr,l,r);
}

vector<int> firstPos, lastPos;
vector<vector<int>> adj;
void eulerTour(int u, int p) {
  firstPos[u] = id;
  Map[id] = u;
  id++;
  for (int v : adj[u])
    if (v != p)
      eulerTour(v, u);
  lastPos[u] = id - 1;
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,u,v,q,tp,z;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    st.resize(4*n);
    lazy.resize(4*n);
    firstPos.resize(4*n);
    lastPos.resize(4*n);
    
    int idx = 0;
    dfs(0,idx);
    vector<int> t(n);
    for(int i = 0;i<n;i++)
        t[mp[i]] = nums[i]^1;
    build(1,t,0,n-1);
    cin>>q;
    
    for(int i= 0;i<q;i++){
        cin>>tp>>z;
        z--;
        if(tp == 2)
            cout<<query(1,0,n-1,ranges[z].x,ranges[z].y)<<endl;
        else
            update(1,0,n-1,ranges[z].x,ranges[z].y);
    }
    return 0;
}