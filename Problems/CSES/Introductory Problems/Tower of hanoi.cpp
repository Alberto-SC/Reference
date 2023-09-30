#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n ==1)
    return cout<<"1 3"<<endl,0;
  
  cout<<3+((n-2)*8)<<endl;
  cout<<"1 2"<<endl;
  cout<<"1 3"<<endl;
  cout<<"2 3"<<endl;
  vector<string> ans = {"1 2","3 2","3 1","2 1","2 3","1 2","1 3","2 3"};
  for(int i = 3;i<=n;i++){
    for(auto c:ans)cout<<c<<endl;
  }
  return 0;
}

