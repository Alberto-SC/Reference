#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

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
  int T =1 ,n;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    int ans = 0;
    for(int i = 0;i<n;i++){
      for(int j = i+1;j<n;j++){
        int dist = nums[j]-nums[i];

        int left = lower_bound(nums.begin(),nums.end(),nums[i]-dist)-nums.begin();

        int right = lower_bound(nums.begin(),nums.end(),nums[j]+dist)-nums.begin();
        right = n-right;

        int x = mod_pow(2,left);
        int y = mod_pow(2,right);
        
        x*=y;
        x%=mod;
        ans+=x;
        ans%=mod;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
