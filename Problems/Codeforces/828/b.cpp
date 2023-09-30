#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n,q,t,x;
  cin>>T;
  while(T--){
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int sum = 0,im = 0,par= 0;
    for(int i = 0;i<n;i++){
      sum+=nums[i];
      im+=nums[i]&1;
      par+=(nums[i]%2)==0;
    }

    while(q--){
      cin>>t>>x;
      if(t ==0){
        sum+=par*x;
        cout<<sum<<endl;
        if(x&1){
          im+=par;
          par = 0;
        }
      }
      else{
        sum+=im*x;
        cout<<sum<<endl;
        if(x&1){
          par+=im;
          im = 0;
        }
      }
    }

  }
  return 0;
}
