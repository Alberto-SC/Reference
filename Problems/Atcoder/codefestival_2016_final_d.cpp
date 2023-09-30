#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long
signed main(){__
  int n,m;
  cin>>n>>m;
  vector<int> nums(n);
  set<int> mp[m];
  map<int,int> mp2;
  for(auto &c:nums)cin>>c,mp2[c]++;
  int ans = 0; 
  for(int i = 0;i<n;i++){
    mp[nums[i]%m].insert(nums[i]);        
  }
  int res = 0;
  for(auto d: mp[0]){
    res+=mp2[d];
  }
  ans +=res/2;   
  
  for(int i = 1;i<=m/2;i++){
    int x1 = 0,y1 = 0,x2 = 0,y2 =0;
    for(auto d:mp[i]){
      x1+= mp2[d]/2;
      if(mp2[d]&1)y1++;
    }
    if(m-i==i){
      ans+=((x1*2)+y1)/2;
      continue;
    }
    for(auto d:mp[m-i]){
      x2 +=mp2[d]/2;
      if(mp2[d]&1)y2++;
    }
    int x = min(y1,y2);
    ans +=x;
    y1-=x;
    y2-=x;
    if(y1!=0){
      int z = min(x2,y1/2);
      ans+= z*2;
      x2-=z;
    }
    else if(y2!=0){
      int z = min(x1,y2/2);
      ans+=z*2;
      x1-=z;
    }
    ans+=x1+x2;
  }
  cout<<ans<<endl;
  return 0;
}
