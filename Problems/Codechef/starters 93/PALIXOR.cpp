#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1<<15;

bool isPalindrome(int x){
  string s = to_string(x);
  int n = s.size();
  for(int i = 0;i<n;i++){
    if(s[i]!=s[n-i-1])return false;
  }
  return true;
}

signed main(){__
  int T = 1,n;
  vector<int> pals;

  for(int i = 1;i<N;i++)
    if(isPalindrome(i))pals.push_back(i);
  
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    vector<int> mp(N+7);
    for(auto &c:nums)cin>>c,mp[c]++;

    int ans = 0;
    for(auto c:pals){
      for(int i = 0;i<N;i++){
        int x = c^i;
        ans+=mp[x]*mp[i];
      }
    }
    ans/=2;
    ans+=n;
    for(int i = 0;i<N;i++){
      ans+=(mp[i]*(mp[i]-1))/2;
    }
    cout<<ans<<endl;
  }
  return 0;
}