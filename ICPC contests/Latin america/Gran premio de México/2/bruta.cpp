#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<pair<int,int>> st;
vector<int> lazy;
int n;
const int mod = 1e9+7;


signed main(){__
  int q,l,r,x;
  cin>>n>>q;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;
  for(int i = 0;i<q;i++){
    char c;
    cin>>c>>l>>r;
    l--,r--;
    if(c=='u'){
      cin>>x;
      for(int i = l;i<=r;i++){
        nums[i]+=x;
      }
    }
    else{
      int ans = 0;
      for(int i = l;i<=r;i++){
        int z = nums[i]%mod;
        ans+=z*z;
        ans%=mod;
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}

