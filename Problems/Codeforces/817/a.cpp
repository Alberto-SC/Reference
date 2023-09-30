#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  string correct = "Timur";
  sort(correct.begin(),correct.end());
  while(T--){
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s==correct)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}

