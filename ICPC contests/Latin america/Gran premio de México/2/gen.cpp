#include <bits/stdc++.h>
using namespace std;
#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

mt19937 rng(accuracy);

int rand(int l,int r){
  uniform_int_distribution<int> ludo(l,r); return ludo(rng);
}


signed main(){
  int n = rand(1000,100000),m = rand(1,100);
  cout<<n<<" "<<m<<endl;
  for(int i = 0;i<n;i++){
    cout<<rand(-100000000,100000000)<<" ";
  }
  cout<<endl;
  for(int i = 0;i<m-2;i++){
    int c =rand(0,1);
    int l = rand(1,n);
    int r = rand(l,n);
    int x = rand(-100000000,100000000);
    if(c==0){
      cout<<"u "<<l<<" "<<r<<" "<<x<<endl;
    }
    else {
      cout<<"q "<<l<<" "<<r<<endl;
    }  
  }
  cout<<"q "<<1<<" "<<1<<endl;
  cout<<"q "<<1<<" "<<n<<endl;
  return 0;
}
