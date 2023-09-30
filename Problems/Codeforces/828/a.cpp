#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    string s;
    cin>>s;
    vector<int> pos[57];
    for(int i = 0;i<n;i++){
      pos[nums[i]].push_back(i);
    }
    bool  flag  = true;
    for(int i = 0;i<=50;i++){
      set<int> st;
      for(auto c:pos[i]){
        st.insert(s[c]);
      }
      if(st.size()>1){
        flag = false;
        break;
      }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
