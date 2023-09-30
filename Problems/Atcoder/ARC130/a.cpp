#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

signed main(){__
  int n;
  cin>>n;
  string s;
  cin>>s;
  int cont = 1,ans = 0;
  for(int i = 1;i<n;i++){
    if(s[i]== s[i-1]){
      cont++;
    }
    else{
      ans+=((cont-1)*cont)/2;
      cont = 1;
    }
  }
  ans+=((cont-1)*cont)/2;
  cout<<ans<<endl;
  return 0;  
}
