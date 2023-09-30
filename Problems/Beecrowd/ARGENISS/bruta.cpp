#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 

signed main(){__
    int T,n,s;  
    cin>>T;
    while(T--){
      cin>>n>>s;
      vector<int> nums(n);
      for(auto &c:nums)cin>>c;
      int ans = 0;
      for(int mask = 1;mask<(1<<n);mask++){
        vector<int> v;
        for(int j = 0;j<n;j++){
          if((mask>>j)&1){
            v.push_back(j);
          }
        }

        do{
          int sum = 0;
          for(int i = 0;i<v.size();i++){
            sum+=2*nums[v[i]];
            if(i)sum+=abs(v[i]-v[i-1]);
            if(i == v.size()-1)sum-=nums[v[i]];
          }
          if(sum<=s){
            ans = max(ans,__builtin_popcount(mask));
          }
        }while(next_permutation(v.begin(),v.end()));
      }
      cout<<ans<<endl;
    }
    return 0;
}



