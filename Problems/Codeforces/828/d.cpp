#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int n2 = 0;
    for(int i = 0;i<n;i++){
      int x = nums[i];
      while(x%2==0){
        n2++;
        x/=2;
      }
    }

    if(n2>=n){
      cout<<0<<endl;
      continue;
    }
    vector<int> best;

    for(int i = 1;i<=n;i++){
      int x = i;
      int cont = 0;
      while(x%2==0){
        cont++;
        x/=2;
      }
      if(cont)
        best.push_back(cont);

    }
    sort(best.rbegin(),best.rend());
    int ans = 0,idx = 0;
    while(n2<n && idx<best.size()){
      n2+=best[idx++];
      ans++;
    }
    if(n2<n){
      cout<<-1<<endl;
    }
    else cout<<ans<<endl;
  }
  return 0;
}
