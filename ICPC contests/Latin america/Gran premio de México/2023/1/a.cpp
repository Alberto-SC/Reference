#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>n;
    map<string,int >mp;
    for(int i = 0;i<n;i++){
      int sz;
      cin>>sz;
      string x;
      for(int j = 0;j<sz;j++){
        string word;
        cin>>word;
        x+=word[0];
      }
      mp[x]++;
    }
    int ans = 0;
    for(auto c:mp){
      if(c.second==1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}