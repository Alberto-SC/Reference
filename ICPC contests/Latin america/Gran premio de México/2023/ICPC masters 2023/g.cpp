#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool isSquare(int x){
  int y = sqrt(x);
  return y*y == x;
}

signed main(){__
  int x;
  cin>>x;
  vector<int> ans;
  for(int i= 1;i<=100000;i++){
    int y = i*i-x;
    if(y<=0)continue;
    if(isSquare(y))ans.push_back(i);
  }
 
  cout<<ans.size();
  if(ans.size()){
    cout<<endl;
    for(int i = 0;i<ans.size();i++){
      cout<<ans[i];
      if(i+1<ans.size())cout<<" ";
    }
  }

  return 0;
}