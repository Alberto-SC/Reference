#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> OP(vector<int> v,int l,int r){
  int n = v.size();
  vector<int> ans;
  for(int i = r+1;i<n;i++){
    ans.push_back(v[i]);
  }
  for(int i = r;i>=l;i--){
    ans.push_back(v[i]);
  }

  for(int i = 0;i<l;i++){
    ans.push_back(v[i]);
  }

  return ans;
}

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int idx = 0,idx2 = 0;
    for(int i = 0;i<n;i++){
      if(nums[i]== n)idx = i;
      if(nums[i]== n-1)idx2 = i;
    }

    if(idx == 0)idx = idx2;
    vector<int> ans(n);
    iota(ans.begin(),ans.end(),1);
    if(idx == n-1){
      for(int i = idx;i>=0;i--){
        ans = max(ans,OP(nums,i,idx));
      }
    }

    for(int i =idx-1;i>=0;i--){
      ans = max(ans,OP(nums,i,idx-1));
    }        

    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
  }
  return 0;
}