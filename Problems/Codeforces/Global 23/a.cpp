#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n,k;
  cin>>T;
  while(T--){
    cin>>n>>k;
    vector<int> nums(n);
    int c0 = 0;
    for(auto &c:nums)cin>>c,c0+=(c==0);
    int c1 = n-c0;
    if(c1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
