#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> st;
vector<int> mx;
int n;
void update(int idx,int x,int v = 1,int sl = 0,int sr = n-1){
  if(sl == sr)st[v] = min(mx[idx],st[v]+x);
  else {
    int m = (sl+sr)/2;
    if(idx<=m)update(idx,x,v<<1,sl,m);
    else update(idx,x,v<<1|1,m+1,sr);

    st[v] = st[v<<1]+st[v<<1|1];
  }
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
  if(sl>r || sr<l || sl>sr)return 0;
  if(sl>=l && sr<=r)return st[v];
  int m = (sl+sr)>>1;
  return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

struct Query {
  int l,r,id;
};

signed main(){__
  int m,q;
  cin>>n>>m>>q;
  mx.resize(n);
  st.resize(4*n);
  for(auto &c:mx)cin>>c;

  vector<pair<int,int>> v;
  
  vector<Query> Q[m];
  vector<int> ans(q);

  for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    v.push_back({a,b});
  }

  for(int i = 0;i<q;i++){
    int d,l,r;
    cin>>d>>l>>r;
    d--,l--,r--;
    Q[d].push_back({l,r,i});
  }

  for(int i = 0;i<m;i++){
    int a,b;
    a = v[i].first;
    b = v[i].second;
    update(a,b);
    for(auto d:Q[i]){
      ans[d.id] = query(d.l,d.r);
    }
  }

  for(auto c:ans)cout<<c<<endl;
}