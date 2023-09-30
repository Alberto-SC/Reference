#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    int neg =0;
    for(auto &c:nums)cin>>c,neg+=(c<0);
    
    int l = 0,r = 0;
    for(int i = 0;i<neg;i++){
      if(nums[i]>0)nums[i]*=-1;
    }
    for(int i = neg;i<n;i++){
      if(nums[i]<0)nums[i]*=-1;
    }

    vector<int> copy = nums;
    sort(copy.begin(),copy.end());
    if(copy ==nums)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}

