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
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int im = 0,pr = 0;
        for(auto &c:nums)cin>>c,im+=c&1;
        pr = n-im;

        int ans = mod_pow(2,pr);
        if(pr == n)ans--;
        if(ans<0)ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}