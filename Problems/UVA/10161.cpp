#include <bits/stdc++.h>
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;

signed main(){__
  int T,n,m;
  vector<int> pows;
  pows.push_back(0);
  for(int i = 1;i<=1000000;i++){
    pows.push_back(i*i);
  }
  while(cin>>n){
    if(n ==0)break;
    int idx = lower_bound(pows.begin(),pows.end(),n)-pows.begin();
    int x,y;
    if(idx &1){
      y = idx;
      if(n == pows[idx])x = 1;
      else{
        int z = pows[idx]-n;
        if(z<=(idx-1)){
          x = z+1;
        }
        else {
          x = idx;
          int t = pows[idx]-(idx-1);
          y-=t-n;
        }
      }
    }
    else{
      x = idx;
      if(n == pows[idx])y = 1;
      else{
        int z = pows[idx]-n;
        if(z<=(idx-1)){
          y = z+1;
        }
        else {
          y = idx;
          int t = pows[idx]-(idx-1);
          x-=t-n;
        }

      }
    }
    cout<<x<<" "<<y<<endl;
  }  
}

