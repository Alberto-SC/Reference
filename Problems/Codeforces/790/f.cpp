#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int t,n,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    vector<int> nums(n);
    map<int,int> mp;
    for(auto &c:nums)cin>>c,mp[c]++;
    vector<int> valids;
    for(auto c:mp){
        if(c.second>=k)valids.push_back(c.first);
    }
    int ans = 0,l =-1,r =-1;
    for(int i = 0;i<valids.size();){
        int j = i+1;
        while(j<valids.size() && valids[j]== valids[j-1]+1){
            j++;
        }  
        if(j-i>ans){
            ans = j-i;
            l = valids[i];
            r = valids[j-1];
        }
        i = j;
    }
    if(l==-1)cout<<-1<<endl;
    else cout<<l<<" "<<r<<endl;
  }
  return 0;
}
