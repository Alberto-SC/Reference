#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    
    int mni = 1e12;
    for(auto &c:nums){
      cin>>c;
      if(c&1)
        mni = min(mni,c);
      
    }
    
    bool fp = true;
    bool fi = true;

    for(int i = 0;i<n;i++){
      if(nums[i]%2==0)continue;
      else if(nums[i]%2==1 && nums[i]==mni)fp = false;
    }

    for(int i = 0;i<n;i++){
      if(nums[i]%2==1)continue;
      else if(nums[i]%2==0 && nums[i]<=mni)fi = false;
    }

    if(fp || fi)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  } 
  return 0;
}