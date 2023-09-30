#include <bits/stdc++.h>
using namespace std;
int main(){
  int t,n;
  cin>>t;
  cout<<fixed<<setprecision(3);
  while(t--){
    cin>>n;
    if(n == 1)cout<<0.0<<endl;
    else if(n==2)cout<<4.0<<endl;
    else {
      int total = n*n;
      int diagonals = (n-2)*(n-2);
      long double x = sqrt(2.0);
      long double ans = (x*diagonals) + (total-diagonals);
      cout<<ans<<endl;
    }
  }
  
  return 0;
}
