#include <bits/stdc++.h>
using namespace std;
//Decompose a tree in many paths that they are consecutive in an array then you can use range algorithms/data structures like segment tree for make querys 
// like sums in a path with updates  v     
const int maxn = 100007;
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
vector<int> p(maxn),head(maxn),stpos(maxn),lvl(maxn),sz(maxn);
vector<int> st;
vector<int> lazy;
vector<int> heavy(maxn,-1);
void propagate(int v,int l,int r){
    if(lazy[v] == 0)return ;
    st[v] += ((r-l)+1)*lazy[v];
    if(l != r){
        lazy[v<<1]+=lazy[v];
        lazy[v<<1|1]+=lazy[v];
    }
    lazy[v] = 0;
}

void update(int v,int sl, int sr,int l,int r,int val){
    propagate(v,sl,sr);
    if(l>sr || r<sl || sl>sr)return;
    if(sl>=l && sr<=r){
        lazy[v]+=val;
        propagate(v,sl,sr);
        return ;
    }
    int mid = (sl+sr)>>1;
    update(v<<1,sl,mid,l,r,val);
    update(v<<1|1,mid+1,sr,l,r,val);
    st[v] = st[v<<1]+st[v<<1|1];
}

int query(int v ,int sl,int sr,int l,int r){
    propagate(v,sl,sr);
    if(l>sr || r<sl || sl>sr)return 0;
    if(sl>=l && sr<=r)
        return st[v];
    int mid = (sl+sr)>>1;
    return query(v<<1,sl,mid,l,r)+query(v<<1|1,mid+1,sr,l,r);
}

int cn = 0;
void dfs(int u ,int pr = -1,int lev = 0){
    lvl[u] = lev;
    sz[u]= 1;
    int mx= 0;
    p[u] = pr;
    for(auto v:graph[u]){
        if(v.x == pr)continue;
        val[v.x] = v.y;
        dfs(v.x,u,lev+1);
        if(sz[v.x]>mx){
            mx = sz[v.x];
            heavy[u] = v.x;
        }
        sz[u]+=sz[v.x];
    }
}

void HLD(int u,int ch,int n){
    head[u] = ch;
    stpos[u] = cn++;
    for(int i=0, currpos = 0; i < n; ++i)
		if(p[i] == -1 || heavy[p[i]] != i)
			for(int j = i; j != -1; j = heavy[j])
			{
				head[j] = i;
				stpos[j] = currpos;
				currpos++;
            }
} 


int query(int a,int b,int n){
    int res = 0;
    while(head[a]!= head[b]){
        if(lvl[head[a]]< lvl[head[b]])
            swap(a,b);
        res += query(1,0,n-1,stpos[head[a]],stpos[a]);
        a = p[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    res+=query(1,0,n-1,stpos[a],stpos[b]);
    return res;
}

int update(int a,int b,int val, int n){ 
    while(head[a] != head[b]){
        if(lvl[head[a]] < lvl[head[b]])
            swap(a,b);
        update(1,0,n-1,stpos[head[a]],stpos[a],val);
        a = p[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    update(1,0,n-1,stpos[a],stpos[b],val);
}

int main(){
    int n,u,v,q;
    cin>>n;
    vector<int> val(n);
    lazy.resize(4*n);
    st.resize(4*n);
    for(auto &c:val)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    dfs(0);
    HLD(0,0);
    for(int i = 0;i<n;i++)
        update(1,0,n-1,stpos[i],stpos[i],val[i]);    
    return 0;
}