#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const long long inf = 1e18;
const int maxn = 100007;

vector<pair<long long,int>> t(2*maxn);
// pair<long long,int> t[2*maxn];
int h = sizeof(int) * 8 - __builtin_clz(maxn);
pair<int,int> d[maxn];  
int n;
void apply(int p, pair<int,int> value) {
    t[p] += value;
    if (p < n) d[p] += value;
}

void build(int p) {
    while (p > 1) p >>= 1, t[p] =min(t[p<<1], t[p<<1|1]) + d[p];
}



void push(int p) {
    for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i].first != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = {0,1e9};
        }
    }
}

void inc(int l, int r, pair<int,int> value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

pair<long long,int> query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    pair<long long,int> res = {inf,0};
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(t[--r], res);
    }
    return res;
}


int Tm = 0;
vector<int> S(maxn),E(maxn);
vector<int> graph[maxn];
vector<int> sz(maxn);

void dfs(int u){
  S[u] = Tm++;
  sz[u] = 1;
  for(auto v:graph[u]){
    dfs(v);
    sz[u]+=sz[v];
  }
  E[u] = Tm-1;
}

signed main(){__
  int T = 1,u,v,q,x;
  cin>>n>>q;

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
    inc(S[i],S[i]+1,{nums[i],i});
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
  
    while(E[u]>S[u]){
      auto mn = query(S[u]+1,E[u]+1);
      if(mn.first>z)break;
      ans[mn.second] = id;
      inc(S[mn.second],S[mn.second]+1,{inf,mn.second});
      completed++;
      break;
    }
    inc(S[u]+1,E[u]+1,{-z,u});
    
    if(ans[u]!=-1){
      id++;
      continue;
    }
    auto head = query(S[u],S[u]+1);
    if(head.first<=z+r){
      ans[u] = id;
      completed++;
      inc(S[u],S[u]+1,{inf,u});
    }
    inc(S[u],S[u]+1,{-(z+r),u});    
    id++;

  }
  for(auto c:ans)cout<<c<<endl;
  return 0;
}