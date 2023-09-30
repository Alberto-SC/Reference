#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int query(int l,int r){
  int x;
  cout<<"? "<<l+1<<" "<<r+1<<endl;
  cin>>x;
  return x;
}

int solve(int l,int r){
  if(l == r)
    return l;

  int m = (l+r)/2;
  int idL = solve(l,m);
  int idR = solve(m+1,r);

  int x = query(idL,idR);
  if(idL+1<idR){
    int y = query(idL,idR-1);
    if(x == y)return idR;
    else return idL;
  }
  else{
    if(x == 1)return idL; 
    else return idR;
  }
}

signed main(){
    int T = 1,n;
    cin>>T;
    while(T--){
      cin>>n;
      int ans = solve(0,n-1);
      cout<<"! "<<ans+1<<endl;    
    }
    return 0;
}