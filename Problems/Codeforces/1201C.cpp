#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int k;
vector<int> x,v;
bool check(int x,vector<int> v){
  int n = v.size();
  int m = n/2;
  int cont = x-v[m];
  v[m] = x;
  for(int i= m+1;i<n;i++){
    if(v[i]<v[i-1]){
      cont+=v[i-1]-v[i];
      v[i]= v[i-1];
    }
  }
  return cont<=k;
}

signed main(){
  int n;
  cin>>n>>k;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;
  sort(nums.begin(),nums.end());

  int l = nums[n/2],r = 2e9+7;
  while(l+1<r){
    int m = (l+r)>>1;
    if(check(m,nums))l = m;
    else r = m;
  }
  cout<<l<<endl;
  return 0;
}
 

