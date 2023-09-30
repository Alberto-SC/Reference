#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 

signed main(){__
  int T = 1,n,m,k;
  cin>>T;
  while(T--){
    cin>>n>>m>>k;
    vector<int> nums(k);
    for(auto &c:nums)cin>>c;
    set<int> st; 
    int need = k;
    int spaces = (n*m)-2;
    int e = spaces-2;
    bool flag = true;
    for(int i = 0;i<k;i++){
      if(nums[i]== need){
        if(st.size()>e){
          flag = false;
          break;
        }
        need--;
        while(st.count(need)){
          st.erase(need);
          need--;
        }
      }
      else{
        st.insert(nums[i]);
        if(st.size()>spaces){
          flag = false;
        }
      }
    }
    if(flag)cout<<"YA"<<endl;
    else cout<<"TIDAK"<<endl;
  }
  return 0;
}
