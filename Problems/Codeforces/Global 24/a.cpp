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
    vector<int> v(n+1);
    for(auto &c:nums)cin>>c,v[c]++;
    cout<<1<<" "<<n<<endl; 
  }
  return 0;
}
