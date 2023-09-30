#include <bits/stdc++.h>
using namespace std;
int main(){
  map<char,int> mp;
  string s;
  cin>>s;
  int n = s.size();
  for(int i = 0;i<n;i++)mp[s[i]]++;

  bool odd = false;
  string o = "";
  string ans = "";
  for(auto c:mp){
    if(c.second&1 && odd)return cout<<"NO SOLUTION"<<endl,0;
    else if(c.second&1){
      odd = true;
      o.push_back(c.first);
    }

    for(int i = 0;i<c.second/2;i++)ans.push_back(c.first);
  }
  string rev = ans;
  reverse(rev.begin(),rev.end());
  if(odd)
    ans+=o;
  ans+=rev;
  cout<<ans<<endl;
  return 0;
}
