#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int t,n,q,x;
  cin>>t;
  while(t--){
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.rbegin(),nums.rend());
    vector<int> ac(n);
    ac[0] =nums[0];
    for(int i = 1;i<n;i++)
        ac[i] = ac[i-1]+nums[i]; 
    for(int i = 0;i<q;i++){
        int l = -1,r = n;
        cin>>x;
        while(l+1<r){
            int m = (l+r)>>1;
            if(ac[m]>=x)
                r = m;
            else 
                l = m;
        }
        if(r == n)cout<<-1<<endl;
        else cout<<r+1<<endl;

    }
  }
  return 0;
}
