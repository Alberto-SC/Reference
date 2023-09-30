#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    vector<int> l(n,-1),r(n,-1);
  
    stack<int> s;

    for(int i = 0;i<n;i++){
      while(s.size() && nums[s.top()]>nums[i]){
        r[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }

    while(s.size())s.pop();

    for(int i = n-1;i>=0;i--){
      while(s.size() && nums[s.top()]>nums[i]){
        l[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }

    vector<int> ans;
    for(int i = 0;i<n;i++){
      if(i ==0 || i == n-1)ans.push_back(-1);
      else if(l[i] ==-1 || r[i]==-1)ans.push_back(-1);
      else ans.push_back((i-l[i]-1)+(r[i]-i-1));
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;

  }
  return 0;
}
