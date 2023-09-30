#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int get(int x,int n){
  if(x>n)return 0;
  if(x&1)
    return 1+get(x*2,n);
  else 
    return 1+get(x*2,n)+get(x+1,n);
}

signed main(){
  map<int,int> mp;
  vector<int> v;
  for(int i = 1;i<=100;i++){
    int x = i;
    while(x>1){
      mp[x]++;
      if(x ==6)v.push_back(i);
      if(x&1)x--;
      else x/=2;
    }
  }

  for(auto c:mp){
    //if(c.first&1)
      //cout<<c.first<<" "<<c.second<<" "<<get(c.first,30)<<endl;
  }
  cout<<get(6,100)<<endl;
  for(auto c:v)cout<<c<<" ";
  cout<<endl;
  return 0;
}
