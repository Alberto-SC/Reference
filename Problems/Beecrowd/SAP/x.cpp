#include <bits/stdc++.h>
using namespace std;

bool isSquare(int x){
    if((int)sqrt(x)*(int)sqrt(x)== x)return true;
    return false;
}


int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  string s;
  cin>>s;
  int n = s.size();
  int ans = n;
  for(int mask = 1;mask<(1<<n);mask++){
    string x = "";
    for(int j = 0;j<n;j++){
      if((mask>>j)&1)
        x+=s[j];
    }
    if(x[0]=='0')continue;
    if(isSquare(stoi(x)))
      ans = min(ans,n-__builtin_popcount(mask));
  }
  if(ans==n)cout<<-1<<endl;
  else cout<<ans<<endl;

  return 0;
}