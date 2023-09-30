#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
signed main(){__
  int t,n;
  cin>>t;
  while(t--){
    string s;
    cin>>n;
    cin>>s;
    bool flag = true;
    for(int i = 0;i<n;){
      int j  = i;
      while(j<n && s[j]== s[i]){j++;}
      if(s[i] == 'W')i = j;
      else {
        if(s[j]== 'W' && i == 0){
          flag = false;break;
        }
        if(j == n && i-1>=0 && s[i-1] =='W'){
          flag = false;break;
        }
        if(i== 0 && j == n ){
          flag = false;break;
        }
        if(s[j] =='W' && s[i-1]== 'W'){
          flag = false;break;
        }
        else i = j;
      }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
