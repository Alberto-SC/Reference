#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


signed main(){__
  int T,n,k;
  cin>>n>>k;

  map<vector<int>,int> mp;

  vector<vector<int>> v(n,vector<int> (k));
  for(int i = 0;i<n;i++){
    for(int j = 0;j<k;j++){
      cin>>v[i][j];
    }
    mp[v[i]] = i;
  }

  vector<int> valid(n);

  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      vector<int> need(k);
      for(int l = 0;l<k;l++){
        if(v[i][l] == v[j][l])need[l] = v[i][l];
        else{
          if(v[i][l] + v[j][l]==3)need[l] = 0;
          if(v[i][l] + v[j][l]==1)need[l] = 2;
          if(v[i][l] + v[j][l]==2)need[l] = 1;
        }
      }
      if(mp.count(need)){
        valid[i]++;
        valid[j]++;
        valid[mp[need]]++;
      }
    }
  }

  int ans = 0;
  for(int i = 0;i<n;i++){
    valid[i]/=3;
    ans+=(valid[i]*(valid[i]-1))/2;
  }
  cout<<ans<<endl;

  return 0;
}
