#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s;
    cin>>s;
    if(n%3 == 1){
      cout<<"YES"<<endl;
      continue;
    }

    vector<int> posR[3][26];  
    for(int i = n-1,j = 0;i>=0;i--,j++)
      posR[j%3][s[i]-'a'].push_back(i);


    bool flag = false;
    for(int i = 0;i<n;i+=3){
      int c = s[i]-'a';
      if(posR[0][c].size()==0 || posR[0][c][0]<i)continue;
      flag = true;
    }

    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
  return 0;
}