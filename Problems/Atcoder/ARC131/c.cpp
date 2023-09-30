#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
signed main(){__
  int n;
  cin>>n;
  vector<int> nums(n);
  int v= 0;
  for(auto &c:nums)cin>>c,v^=c;
  if(n&1)cout<<"Win"<<endl;
  else{
    bool WIN = false;
    for(int i = 0;i<n;i++)
      if(nums[i]== v)WIN = true;
    if(WIN)cout<<"Win"<<endl;
    else cout<<"Lose"<<endl;
  }
  return 0;
}
