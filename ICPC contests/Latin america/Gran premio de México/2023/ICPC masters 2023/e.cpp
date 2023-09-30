#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

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
  int n,d,k,s;
  cin>>n>>d>>k>>s;  

  if(d == 0 || n == 1)return cout<<k<<endl,0;

  int x = min(n,(2*d)+1);
  int invx = mod_pow(x-1,mod-2);
  int ans = mod_pow(x,k)-1;
  if(ans<0)ans+=mod;
  (ans*=invx)%=mod;
  
  cout<<ans<<endl;
}