#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long

bool check(int x,vector<pair<int,int>> v){
  int a = x-1,b = 0,n = v.size();
  for(int i = 0;i<n;i++){
    if(v[i].first>=a && v[i].second >=b){
      a--,b++;
    }
    if(b == x)return true;
  }
  return false;
}

signed main(){__
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    vector<pair<int,int>> nums(n);
    for(int i = 0;i<n;i++){
      cin>>nums[i].first>>nums[i].second;
    }
    int l = 1,r =n+1;
    while(l+1<r){
      int m = (l+r)>>1;
      if(check(m,nums))
        l = m;
      else r = m;
    }
    cout<<l<<endl;
  }
  return 0;
}
