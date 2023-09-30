#include <bits/stdc++.h>
using namespace std;
#define int long long

int count(int x){
  if(x==0)return 0;
  int nd = 0;
  int p = 10;
  while(p<=x){
    p*=10;
    nd++;
  }
  int ans = 0;
  int s = 9;
  for(int i = 1;i<=nd;i++){
    ans+=s*i;
    s*=10;
  }
  int pow10 = pow(10,nd);
  x-=pow10;
  x++;
  ans+= x*(nd+1);
  //cout<<ans<<" "<<nd<<" "<<pow10<<" "<<p<<endl;
  return ans;
}

signed main(){
  int q,k;
  cin>>q;
  //cout<<count(10)<<endl;
  while(q--){
    cin>>k;
    int l = 1,r = 1e17;
    while(l+1<r){
      int m = (l+r)>>1;
      if(count(m)<=k)l = m;
      else r = m;
    }
    if(count(l)!=k)l++;
    vector<int> digits;
    int x = count(l-1);
    while(l){
      digits.push_back(l%10);
      l/=10;
    }
    int need = k-x;
    need--;
    reverse(digits.begin(),digits.end());
    cout<<digits[need]<<endl;
  }
}



