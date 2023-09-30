#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> bit[2];
int n;
int sum(int idx,int who) {
  int ret = 0;
  for (++idx; idx > 0; idx -= idx & -idx)ret +=bit[who][idx];
  return ret;
}

int sum(int l, int r,int who) {
    return sum(r,who) - sum(l-1,who);
}

void add(int idx, int delta,int who) {
    for (++idx; idx <= n; idx += idx & -idx) bit[who][idx] += delta;
}

void print(){
  for(int i = 0;i<n;i++){
    cout<<sum(i,i,0)<<" ";
  }
  cout<<endl;
}


const int mod = 1e9+7;

int mod_pow(int a,int b){
  int x = 1;
  while(b){
    if(b&1)(x*=a)%=mod;
    (a*=a)%=mod;
    b>>=1;
  }
  return x;
}

signed main(){__
  int T = 1,q;
  cin>>n>>q;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;

  bit[0].resize(n+7);
  bit[1].resize(n+7);


  for(int i = 0;i<n;i++){
    add(i,nums[i],0);
    add(i,nums[i]*nums[i],1);
  }


  const int inv2 = mod_pow(2,mod-2);

  while(q--){
    int l,r;
    cin>>l>>r;
    l--,r--;

    int x = sum(l,r,0);
    x%=mod;
    x*=x;
    x%=mod;

    int y = sum(l,r,1);
    y%=mod;

    int ans = (x-y);
    if(ans<0)ans+=mod;
    (ans*=inv2)%=mod;
    cout<<ans<<endl;
  }

  return 0;
}