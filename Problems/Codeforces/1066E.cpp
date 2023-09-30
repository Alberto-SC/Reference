#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 

const int mod = 998244353;

int mod_pow(int a,int b){
  int x = 1;
  while(b){
    if(b&1)(x*=a)%=mod;
    (a*=a)%=mod;
    b>>=1;
  }
  return x;
}

signed main(){
  int n,m;
  cin>>n>>m;
  string s;
  string t;
  cin>>s>>t;
  if(n<m)
    s = string(m-n,'0')+s,n = m;
  if(m<n)
    t = string(n-m,'0')+t,m = n;

  vector<int> ac(n);

  ac[0]= t[0]=='1';
  for(int i =1;i<n;i++)
    ac[i] = ac[i-1]+(t[i]=='1');
 
  int ans =0;
  for(int i = 0;i<n;i++){
    if(s[i]=='1'){
      ans+=mod_pow(2,(n-1)-i)*ac[i];
      ans%=mod;
    }
  }
  cout<<ans<<endl;
  return 0; 
}
