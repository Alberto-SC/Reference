#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
vector<pair<int,int>> ranges;

void addranges(int l,int r){
  if(l == r)return ;
  ranges.push_back({l,r});
  int m = (l+r)>>1;
  addranges(l,m);
  addranges(m+1,r);
}

signed main(){__
  int T,n;
  cin>>T;

  
  while(T--){
    cin>>n;
    ranges.clear();
    addranges(0,7);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int log = log2(nums);
    vector<int> moves(n);
    for(int i = 0;i<n;i++){
      int current = i;
      int need = nums[i]-1;
      for(int j = log-1;j>=1;j++){
        if(need[])
      }   
    }  
    for(auto c:){

    }
  }
  
  return 0;
}

