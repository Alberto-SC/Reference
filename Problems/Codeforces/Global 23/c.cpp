#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


void solve(vector<int> &nums){
  int n = nums.size();
  vector<int> idx(n+1);
  int ac = 0;
  int last = 0;
  bool flag = false;
  set<int> st;
  for(int i = 1;i<=n;i++){
    st.insert(i);
  }
  
  for(int i = 0;i<n;i++){
    if(nums[i]+ac>last){
      last = nums[i]+ac;
      continue;
    }
    int x = last-(nums[i]+ac);
    auto y = st.lower_bound(x);
    if(y == st.end()){
      y--;
    }
    ac+=*y;
    idx[*y] = i+1;
    st.erase(y);
    last = nums[i]+ac;
  }

  for(auto c:st){
    idx[c] = n;
  }

  for(int i = 1;i<=n;i++){
    cout<<idx[i]<<" ";
  }
  cout<<endl; 
}

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    solve(nums);
   
  }
  return 0;
}
