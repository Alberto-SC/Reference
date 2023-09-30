#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n,k;
  cin>>T;
  while(T--){
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    vector<int> a = nums;
    sort(a.begin(),a.end());
    set<int> st;
    for(int i = 0;i<k;i++){
      st.insert(a[i]);
    } 
    for(int i = 0;i<k;i++){
      st.erase(nums[i]);
    }
    cout<<st.size()<<endl;
  }
  return 0;
}
