#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T;
  int ac = 2;
  int id = 1;
  int x = 4;
  vector<int> pref;
  pref.push_back(ac);
  while(ac<1000000000){
    ac+=x;
    pref.push_back(ac);
    if(id%3 ==2)x+=2;
    if(id%3 ==0)x+=2;
    id++;
  }
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    int id = lower_bound(pref.begin(),pref.end(),n)-pref.begin();
    cout<<id+2<<endl;
  }
  return 0;
}
