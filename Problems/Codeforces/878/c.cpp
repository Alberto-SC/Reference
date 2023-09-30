#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int get(int x){
  return (x*(x+1))/2;
}

signed main(){__
  int T = 1,n,k,q;
  cin>>T;
  while(T--){
    cin>>n>>k>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> v;
    v.push_back(-1);
    for(int i = 0;i<n;i++){
      if(nums[i]>q)v.push_back(i);
    }
    v.push_back(n);

    int ans = 0;
    for(int i =1;i<v.size();i++){
      int len = v[i]-v[i-1]-1;
      if(len<k)continue;
      int T = len-k+1;
      ans+=(T*len)-(get(len)-get(k-1))+T;
    }
    cout<<ans<<endl;
  }
  return 0;
}