#include <bits/stdc++.h>
using namespace std;
#define int long long 

int LCM(int a,int b){
  return a*b/__gcd(a,b);
}

signed main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int lcm = 1;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,lcm = LCM(lcm,c);
    cout<<lcm<<endl;

  }
  return 0;
}
