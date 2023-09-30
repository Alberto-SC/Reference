#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> ans(n);
    iota(ans.begin(),ans.end(),1);
    if(n%2==0){
      reverse(ans.begin(),ans.end());
      for(auto c:ans)cout<<c<<" ";
      cout<<endl;
    }
    else{
      if(n==3)cout<<-1<<endl;
      else{
        rotate(ans.begin(),ans.begin()+n/2,ans.end());
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
      }

    }
  }
  
  return 0;
}

