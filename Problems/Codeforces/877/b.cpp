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
    for(auto &c:nums)cin>>c;
    vector<int> pos(n+1);
    for(int i = 0;i<n;i++){
      pos[nums[i]] = i+1;
    }

    if(abs(pos[1]-pos[2])>1)
      cout<<min(pos[2]+1,pos[1]+1)<<" "<<pos[n]<<endl;
    else if(pos[n]>max(pos[1],pos[2]))
      cout<<max(pos[1],pos[2])<<" "<<pos[n]<<endl;
    else
      cout<<min(pos[1],pos[2])<<" "<<pos[n]<<endl;
  }
  return 0;
}