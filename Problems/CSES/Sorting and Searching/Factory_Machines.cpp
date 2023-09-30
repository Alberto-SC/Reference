#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

bool check(int t,vector<int> v,int x){
  int count = 0;
  int n= v.size();
  for(int i = 0;i<n;i++){
    count+=t/v[i];
    if(count>=x)return true;
  }
  return false;
}

signed main(){
  int n,t;
  cin>>n>>t;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;

  int l =0 ,r  = 1e18;
  while(l+1<r){
    int m = (l+r)>>1;
    if(check(m,nums,t))r = m;
    else l = m;
  }
  cout<<r<<endl;
  return 0;
}

