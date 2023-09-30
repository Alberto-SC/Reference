//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define x first
#define y second
const int maxn = 200007;
vector<pair<int,int>> graph[maxn];
vector<int> p(maxn),head(maxn),stpos(maxn),lvl(maxn),sz(maxn),val(maxn);
vector<int> st;
vector<int> lazy;
vector<int> heavy(maxn,-1);

const int inf = 1e9+1;

void propagate(int v,int l,int r){
  if(!lazy[v])return ;
  st[v] = lazy[v];
  if(l!=r){
    lazy[v<<1] = lazy[v];
    lazy[v<<1|1] = lazy[v];
  }
  lazy[v] = 0;
}
int n;
void update(int l,int r,int x,int v = 1,int sl = 0,int sr =n-1){
  propagate(v,sl,sr);
  if(sl> r || sr <l || sl>sr) return ;
  if(sl>=l && sr<=r){
    lazy[v] = x;
    propagate(v,sl,sr);
    return ;
  }
  int m = (sl+sr)>>1;
  update(l,r,x,v<<1,sl,m);
  update(l,r,x,v<<1|1,m+1,sr);
  st[v] = min(st[v<<1],st[v<<1|1]);
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
  propagate(v,sl,sr);
  if(sl>r || sr<l || sl>sr)return inf;
  if(sl>=l && sr<=r)return st[v];
  int m = (sl+sr)>>1;
  return min(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

map<pair<int,int>,bool> mp; 

vector<bool> vis(maxn);
void dfs(int u,int pr = -1,int lev = 0){
  lvl[u] = lev;
  sz[u] = 1;
  int mx = 0;
  p[u] = pr;
  vis[u] = true;
  if(pr!=-1){
    mp[{u,pr}] = true;
  }
  for(auto v:graph[u]){
    if(vis[v.x])continue;
    val[v.x] = v.y;
    dfs(v.x,u,lev+1);
    if(sz[v.x]>mx){
      mx = sz[v.x];
      heavy[u] = v.x;
    }
    sz[u]+=sz[v.x];
  }
}

void HLD(){
  for(int i = 0, currpos = 0;i<n;i++){
    if(p[i]==-1 || heavy[p[i]]!=i){
      for(int j = i;j!=-1;j=heavy[j]){
        head[j] = i;
        stpos[j] = currpos++;
      }
    }
  }
}

int queryHLD(int a,int b){
  int res = inf;
  while(head[a]!=head[b]){
    if(lvl[head[a]]< lvl[head[b]])
      swap(a,b);
    res = min(res,query(stpos[head[a]],stpos[a]));
    a = p[head[a]];
  }
  if(lvl[a]>lvl[b])
    swap(a,b);
  res+=query(stpos[a]+1,stpos[b]);
  return res;
}

void updateHLD(int a,int b,int val){
  while(head[a]!=head[b]){
    if(lvl[head[a]]< lvl[head[b]])
      swap(a,b);
    update(stpos[head[a]],stpos[a],val);
    a = p[head[a]];
  }
  if(lvl[a]>lvl[b])
    swap(a,b);
  update(stpos[a]+1,stpos[b],val);
}

void print(){
  for(int i = 0;i<n;i++){
    cout<<query(i,i)<<" ";
  }
  cout<<endl;
}

signed main(){__
  int m,u,v,w,q;
  cin>>n>>m;
  vector<pair<int,int>> E;
  st.resize(4*n);
  lazy.resize(4*n);
  for(int i = 0;i<m;i++){
    cin>>u>>v>>w;
    u--,v--;
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
    E.push_back({u,v});
  } 

  dfs(0);
  HLD();

  for(int i= 0;i<n;i++){
    update(stpos[i],stpos[i],val[i]);
  }
    
  for(int i = 0;i<m;i++){
    if(!mp.count(E[i]) && !mp.count({E[i].y,E[i].x})){
      updateHLD(E[i].x,E[i].y,inf);
    }
  }
  cin>>q; 
  while(q--){
    cin>>u>>v>>w;
    u--,v--;
    updateHLD(u,v,inf);
    int x = query(1,n-1);
    if(x==inf)cout<<-1<<endl;
    else cout<<x<<endl;
  }

}


