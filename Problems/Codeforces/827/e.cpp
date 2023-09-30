#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n,q,x;
  cin>>T;
  while(T--){
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> mx(n);
    vector<int> pref(n);
    mx[0] = nums[0];
    pref[0] = nums[0];
    for(int i= 1;i<n;i++){
      mx[i] = max(mx[i-1],nums[i]);
      pref[i] = pref[i-1]+nums[i];
    }

    while(q--){
      cin>>x;
      int l = -1,r = n;
      while(l+1<r){
        int m = (l+r)>>1;
        if(mx[m]<=x)
          l = m;
        else 
          r = m;
      }
      if(l==-1)cout<<0<<" ";
      else 
        cout<<pref[l]<<" ";
    }
    cout<<endl;
  }
  return 0;
}

