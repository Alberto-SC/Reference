#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 

int isSquare(int x){
  int l = 0 ,r = 1e9;
  while(l+1<r){
    int m = (l+r)>>1;
    if(m*m>=x)
      r = m;
    else 
      l = m;
  }
  return r;
}

signed main(){__
  int n;
  cin>>n;
  vector<int> nums(n/2);
  for(auto &c:nums)cin>>c;
  vector<int> ans;

  int last = 1;
  int x = n/2;
  int idx = 0;
  bool flag = true;
  int lastSquare = 0;
  while(x--){
    int sum = last;
    while(sum<1e13 && last+2<=nums[idx]){
      int x = isSquare(lastSquare+sum+nums[idx]);
      if(x*x == lastSquare+sum+nums[idx])break;
      last+=2;
      sum+=last;
    }
    int newLast = isSquare(lastSquare+ sum+nums[idx]);
    if(newLast*newLast != lastSquare+sum+nums[idx]){
      flag = false;
      break;
    }
    ans.push_back(sum);
    ans.push_back(nums[idx++]);
    last = (newLast*2)+1;
    lastSquare = newLast*newLast;
  }

  if(flag){
    cout<<"Yes"<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
  }
  else{
    cout<<"No"<<endl;
  }

  return 0;
}
