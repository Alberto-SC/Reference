#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


const int maxn = 2000007;
vector<int> bit(maxn);

int sum(int idx){
    int ans = 0;
    for(++idx;idx>0; idx-=idx&-idx)ans +=bit[idx];
    return ans;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}

void add(int idx,int v){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=v;
}
signed main(){__
  int t,n;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      vector<int> nums(n);
      vector<int> b(n+1);
      for(auto &c:nums)cin>>c,b[c]++;
      for(int i = 1;i<=n;i++)
          add(i,b[i]);
      
      vector<bool> used(n+1);
      int ans = 0;
      for(int i = 0;i<n;i++){
         ans+=sum(nums[i]-1);
         add(nums[i],-1);
         if(!used[nums[i]])
            ans+=(b[nums[i]]*(b[nums[i]]-1))/2,used[nums[i]] = true;
      }
      cout<<ans<<endl;
  }
  return 0;
}
