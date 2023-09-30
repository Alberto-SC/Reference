#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(int x,vector<int> &v){
  vector<pair<int,int>> P;
  for(auto c:v){
    int l = c-x,r = c+x;
    P.push_back({l,r});
  }

  int C = 1;
  sort(P.begin(),P.end());

  int L = -1e12,R = 1e12;
  for(int i = 0;i<P.size();i++){
    if(P[i].first>R){
      C++;
      L = P[i].first;
      R = P[i].second;
    }
    else{
      L = max(L,P[i].first);
      R = min(R,P[i].second);
    }
  }

  return C<=3;
}

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    int l = -1,r = 1e9;
    while(l+1<r){
      int m = (l+r)>>1;
      if(check(m,nums))r = m;
      else l = m;
    }
    cout<<r<<endl;
  }
  return 0;
}