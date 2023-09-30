#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){
  int n;
  cin>>n;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;

  int ans = 0;
  for(int i = 0;i<n;){
    int j = i;
    while(j<n && nums[i]== nums[j]){
      j++;
    }
    int len = j-i;
    ans += (len*(len+1))/2;
    i = j;
  }
  cout<<ans<<endl;
  return 0;
}
