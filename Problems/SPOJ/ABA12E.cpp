#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long

vector<int> ac;
int n;
int check(int x){
  int poss = 0;
  for(int i = 0;i<n;i++){
    int l = i-1,r = n;
    while(l+1<r){
      int m = (l+r)>>1;
      if(ac[m]-(i?ac[i-1]:0)>=x)
        r = m;
      else 
        l = m;
    }
    poss+=n-r;
  }
  return poss;
}

signed main(){__
  int k;
  cin>>n>>k;
  vector<int> nums(n);
  for(auto &c:nums)cin>>c;
  ac = nums;
  for(int i = 1;i<n;i++)
    ac[i]+=ac[i-1];
  int l = 0,r = 1e16;
  int total = (n*(n+1))/2;
  k--;
  while(l+1<r){
    int m = (l+r)>>1;
    int x = check(m);
    if(x>=total-k)
      l = m;
    else 
      r = m;
  }

  cout<<l<<endl;
  return 0;
}
