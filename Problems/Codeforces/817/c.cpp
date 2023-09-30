#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s;
    map<string,int> mp;
    vector<string> v[3];
    for(int i=0;i<3;i++){
      for(int j = 0;j<n;j++){
        cin>>s;
        mp[s]++;
        v[i].push_back(s);
      }
    }

    for(int i = 0;i<3;i++){
      int ans = 0;
      for(auto c:v[i]){
        if(mp[c]==1)ans+=3;
        else if(mp[c]==2)ans+=1;
      }
      cout<<ans<<" ";
    }
    cout<<endl;
  }
}

