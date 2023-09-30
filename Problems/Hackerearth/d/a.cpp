#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;
#define x first 
#define y second
const int maxn = 500007;
vector<pair<int,int>> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back({v,0});
    graph[v].push_back({u,0});
}
vector<int> parent(maxn),head(maxn),stpos(maxn),lvl(maxn),sizes(maxn);
vector<int> st;
vector<int> lazy;
vector<int> heavy(maxn,-1),val(maxn);
int n; 
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
    st[v] += lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}
void updateST(int l,int r,int val,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    updateST(l,r,val,v<<1,sl,m);
    updateST(l,r,val,v<<1|1,m+1,sr);
    st[v] = max(st[v<<1],st[v<<1|1]);
}

int queryST(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return max(queryST(l,r,v<<1,sl,m),queryST(l,r,v<<1|1,m+1,sr));
}

void dfs(int u ,int pr = -1,int lev = 0){
    lvl[u] = lev;
    sizes[u]= 1;
    int mx= 0;
    parent[u] = pr;
    for(auto v:graph[u]){
        if(v.x == pr)continue;
        // val[v.x] = v.y;
        dfs(v.x,u,lev+1);
        if(sizes[v.x]>mx){
            mx = sizes[v.x];
            heavy[u] = v.x;
        }
        sizes[u]+=sizes[v.x];
    }
}

void HLD(int u){
    for(int i=0, pos = 0; i<n; i++)
		if(parent[i] == -1 || heavy[parent[i]] != i)
			for(int j = i; j != -1; j = heavy[j]){
				head[j] = i;
				stpos[j] = pos;
				pos++;
            }
} 


int query(int a,int b){
    int res = 0;
    while(head[a]!= head[b]){
        if(lvl[head[a]]< lvl[head[b]])
            swap(a,b);
        res = max(res,queryST(stpos[head[a]],stpos[a]));
        a = parent[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    res = max(res,queryST(stpos[a],stpos[b]));
    return res;
}


int update(int a,int b,int val){ 
    while(head[a] != head[b]){
        if(lvl[head[a]] < lvl[head[b]])
            swap(a,b);
        updateST(stpos[head[a]],stpos[a],val);
        a = parent[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    updateST(stpos[a],stpos[b],val);
}

int main(){__
    int u,v,q;
    cin>>n>>q;
    lazy.resize(4*n);
    st.resize(4*n);
    for(int i = 0;i<n;i++)
        cin>>val[i];
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    dfs(0);
    HLD(0);
    for(int i = 0;i<n;i++)
        updateST(stpos[i],stpos[i],val[i]);    
	for(int i = 0;i<q;i++){
		cin>>u>>v;
		u--,v--;
		cout<<query(u,v)<<endl;
	}
    return 0;
}