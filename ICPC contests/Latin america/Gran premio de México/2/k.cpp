#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<pair<int,int>> st;
vector<int> lazy;
int n;
const int mod = 1e9+7;

void propagate(int v,int l,int r){
  if(lazy[v]==0)return;
  int L = (r-l)+1;
  int z = lazy[v]%mod;
  int y2 = z*z;
  y2%=mod;
  int x = L*y2;
  x%=mod;
  int smod = st[v].second%mod;
  int y = 2*z*smod;
  y%=mod;
  y+=mod;
  y%=mod;
  //if(l == 0 && r ==0){
  //cout<<lazy[v]<<" "<<L<<endl;
  //cout<<lazy[v]*L<<endl;
  //}
  st[v].first += x+y;
  st[v].first %= mod;
  st[v].second += lazy[v]*L;
  if(l!=r){
    lazy[v<<1]+=lazy[v];
    lazy[v<<1|1]+=lazy[v];
  }
  lazy[v] = 0; 
}

pair<int,int> merge(pair<int,int> a,pair<int,int> b){
  pair<int,int> ans;
  ans.first = (a.first+b.first)%mod;
  ans.second = (a.second+b.second);
  return ans;
}

void update(int l,int r,int x,int v = 1,int sl = 0,int sr = n-1){
  propagate(v,sl,sr);
  if(sl>r || sr<l ||sl >sr)return ;
  if(sl>=l && sr<=r){
    lazy[v] += x;
    propagate(v,sl,sr);
    return ;
  }
  int m = (sl+sr)>>1;
  update(l,r,x,v<<1,sl,m);
  update(l,r,x,v<<1|1,m+1,sr);
  st[v] = merge(st[v<<1],st[v<<1|1]);
} 

pair<int,int> query(int l,int r,int v = 1,int sl =0,int sr = n-1){
  propagate(v,sl,sr);
  if(sl>r || sr<l || sl>sr)return {0,0};
  if(sl>=l && sr<=r)return st[v];
  int m = (sl+sr)>>1;
  return merge(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

void print(){
  for(int i = 0;i<n;i++){
    pair<int,int> x = query(i,i);
    cout<<x.first<<" "<<x.second<<endl;
  }
  cout<<endl;
}

signed main(){__
  int q,l,r,x;
  cin>>n>>q;
  st.resize(4*n);
  lazy.resize(4*n);
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;
  for(int i = 0;i<n;i++){
    update(i,i,nums[i]);
  }
  for(int i = 0;i<q;i++){
    char c;
    cin>>c>>l>>r;
    l--,r--;
    if(c=='u'){
      cin>>x;
      update(l,r,x);
    }
    else{
      cout<<query(l,r).first<<endl;
    }
  }
  return 0;
}

