#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i = 0;i<n;i++){
    cin>>nums[i];
  }
  int ans = 0;
  set<string> st;
  int L = 1;
  int R = 1;
  for(int i = 0;i<n-1;i++){
    L *=nums[i];
  }
  for(int i = n-1;i>=1;i--){
    L/=nums[i-1];
    for(int j = nums[i];j<=99;j++){
      string s = to_string(j);
      for(int k = 0;k<=9;k++){
        string t = s[0]+ to_string(k)+ s[1];
        for(int l = 0;l<=9;l++){
          string z = to_string(l)+t[0];
          if(stoll(z)<=nums[i-1]){
            st.insert(z+t[1]+t[2]);
          }
        }
      }
      for(int k = 0;k<=9;k++){
        string t = s+to_string(k);
        for(int l = 0;l<=9;l++){
          for(int l = 0;l<=9;l++){
            string z = to_string(l)+t[0];
            if(stoll(z)<=nums[i-1]){
              st.insert(z+t[1]+t[2]);
            }
          }

        }
      }
    }
    cout<<st.size()<<" "<<L<<" "<<R<<endl;
    ans+=st.size()*L*R;
    R*= nums[i];
  }
  cout<<ans<<endl;
  return 0;
}
