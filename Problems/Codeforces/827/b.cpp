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
    set<int> st;
    for(auto &c:nums)cin>>c,st.insert(c);
    if(st.size( )==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}

