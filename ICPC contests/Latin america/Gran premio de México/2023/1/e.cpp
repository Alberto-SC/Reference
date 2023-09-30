#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const long long inf = 1e16;
vector<pair<int,int>> st;
vector<long long> lazy;
int n;
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
    st[v].first += lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}
void update(int l,int r,long long val,int id = 0,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        if(l == r)st[v].second = id;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    update(l,r,val,id,v<<1,sl,m);
    update(l,r,val,id,v<<1|1,m+1,sr);
    st[v] = min(st[v<<1],st[v<<1|1]);
}

pair<int,int> query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return {inf,0}; 
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return min(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}


const int maxn = 100007;
int t = 0;
vector<int> S(maxn),E(maxn);
vector<int> graph[maxn];
vector<int> sz(maxn);

void dfs(int u){
  S[u] = t++;
  sz[u] = 1;
  for(auto v:graph[u]){
    dfs(v);
    sz[u]+=sz[v];
  }
  E[u] = t-1;
}

signed main(){__
  int T = 1,u,v,q,x;
  cin>>n>>q;
  st.resize(4*n);
  lazy.resize(4*n);

  vector<int> nums(n);
  for(auto &c:nums)cin>>c;

  vector<int> inDegree(n);
  for(int i = 0;i<n-1;i++){
    cin>>u>>v;
    u--,v--;
    graph[u].push_back(v);
    inDegree[v]++;
  }

  int root = 0;
  for(int i = 0;i<n;i++){
    if(inDegree[i]==0)root = i;
  }

  dfs(root);

  for(int i = 0;i<n;i++){
    update(S[i],S[i],nums[i],i);
  }

  int id = 1;
  int completed = 0;
  vector<int> ans(n,-1);
  while(q--){
    cin>>u>>x;
    u--;

    int z = x/sz[u];
    int r = x-(z *sz[u]);

    if(completed == n)continue;
    while(1){
      auto mn = query(S[u]+1,E[u]);
      if(mn.first>z)break;
      ans[mn.second] = id;
      update(S[mn.second],S[mn.second],inf,mn.second);
      completed++;
    }
    update(S[u]+1,E[u],-z);
    
    if(ans[u]!=-1){
      id++;
      continue;
    }
    auto head = query(S[u],S[u]);
    if(head.first<=z+r){
      ans[u] = id;
      completed++;
      update(S[u],S[u],inf,u);
    }
    update(S[u],S[u],-(z+r),u);    
    id++;

  }
  for(auto c:ans)cout<<c<<endl;
  return 0;
}