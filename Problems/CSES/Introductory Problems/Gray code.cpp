#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n ==1)
    cout<<"0\n1"<<endl;
  
  vector<int> ans;
  ans.push_back(0);
  ans.push_back(1);
  ans.push_back(3);
  ans.push_back(2);
  for(int i = 3;i<=n;i++){
    
    int idx = (1<<(i-1))-1;
      
    int x = 1<<(i-1);
    for(int j = 0;j<(1<<(i-1));j++){
      ans.push_back(x|ans[idx--]);
    }
  }
  for(auto c:ans){
    for(int i = n-1;i>=0;i--){
      if((c>>i)&1)cout<<1;
      else cout<<0;
    }
    cout<<endl;
  } 
  return 0;
}
