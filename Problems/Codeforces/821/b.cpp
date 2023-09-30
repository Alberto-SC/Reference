#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){
  int T,n,x,y;
  cin>>T;
  while(T--){
    cin>>n>>x>>y;
    if((x!=0 && y!= 0) ||( x ==0 && y==0))cout<<-1<<endl;
    else{
      if((n-1)%max(x,y))cout<<-1<<endl;
      else {
        int last = 1;
        for(int i = 0;i<n-1;i++){
         if(i && i%max(x,y) ==0)last+=x+1;
          cout<<last<<" ";
        }
        cout<<endl;
      }
    }
  }
  return 0;
}
