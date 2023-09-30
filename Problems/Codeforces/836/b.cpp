#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    if(n&1){
      for(int i = 0;i<n;i++)cout<<1<<" ";
      cout<<endl;
    }
    else{
      cout<<"1 3 ";
      for(int i = 0;i<n-2;i++)cout<<"2 ";
      cout<<endl;
    }
  }
  return 0;
}
