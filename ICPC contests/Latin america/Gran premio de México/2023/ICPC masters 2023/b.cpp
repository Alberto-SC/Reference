#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
  int T = 1,C,n,m;
  cin>>C>>n>>m;
  unordered_map<int,int> mp;
  for(int i = 0;i<n;i++){
    int x;
    cin>>x;
    mp[x]++;
  }

  vector<int> ans(54);
  for(int i = 0;i<54;i++){
    int res = 0;
    for(auto c:mp){
      res+=c.second;
    }
    ans[i] = res;
    unordered_map<int,int> nwmp; 
    for(auto c:mp){
      int nw = c.first*2;
      if(nw>C){
        int n1 = ceil(nw/2.0);
        int n2 = floor(nw/2.0);
        n1 = ((n1+1000-1)/1000)*1000;
        n2 = (n2/1000)*1000;
        nwmp[n1]+=c.second;
        nwmp[n2]+=c.second;
      }
      else nwmp[nw]+=c.second;
    }
    mp = nwmp;
  }


  for(int i = 0;i<m;i++){
    int x;
    cin>>x;
    cout<<ans[x]<<endl;
  }

  return 0;
}