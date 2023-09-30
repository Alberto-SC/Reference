#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
  int n;
  cin>>n;
  int ans = 0;
  for(int i = 1;i<=1000000;i++){
      int x = (i*i)-i-n;
      if(x>0)break;
      if(x<0 && -x%i == 0 && (-x/i)&1)ans++;
  }
  cout<<ans<<endl;
  return 0;
}
