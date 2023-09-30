#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
  int q,l,r;
  cin>>q;
  vector<int> ac(1000000+1);
  for(int i = 1;i<=1000000;i++){
    int x = i;
    vector<int> mp(10);
    int cont = 0;
    while(x){
      cont++;
      mp[x%10]++;
      x/=10;
    }
    bool flag = mp[0]==0;
    for(int j = 1;j<=cont;j++)
       flag &= mp[j]==1;
    for(int j = cont+1;j<=9;j++)
       flag &= mp[j]==0;
    ac[i] = flag; 
  }
  for(int i = 1;i<ac.size();i++)
    ac[i] +=ac[i-1];

  while(q--){
    cin>>l>>r;
    cout<<ac[r]-ac[l-1]<<endl;
  }
  return 0;
}
