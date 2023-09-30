#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    vector<int> ans(n);
    int id = n;
    for(int i = 0;i<n;i++){
      ans[i] = id--;
    }

    bool z = false;
    do{
      bool flag = true;
      for(int i = 1;i<=n;i++){
        if(i == 1 && v[i-1]!=x)flag = false;
        if(i == n && v[i-1]!=1)flag = false;
        if(i!= 1 && i!= n && v[i-1]%i)flag = false;
      }
      if(flag){
        ans = min(ans,v),z = true;
      }

    }while(next_permutation(v.begin(),v.end()));
    if(!z)cout<<-1<<endl;
    else{
      for(auto c:ans)cout<<c<<" ";
      cout<<endl;
    }
  }
  return 0;
}
