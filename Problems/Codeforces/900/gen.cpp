#include <bits/stdc++.h>

using namespace std;

int main(){
  int n = 200000;
  cout<<n<<endl;
  for(int i = 0;i<n;i++){
    cout<<(1<<(min(i,29)))<<" ";
  }
  cout<<endl;
  for(int i = 1;i<n;i++){
    cout<<i<<" "<<i+1<<endl;
  }
  int q = 100000;

  for(int i = 0;i<q;i++){
    cout<<1<<" "<<n<<endl;
  }
}