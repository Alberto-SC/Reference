#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(null);
#define endl '\n'

vector<int> b[3];
int C,X,T;
bool check(int x){
  for(int i = 0;i<3;i++){
    int lastL = 0;
    int idx = 0,lastidx = 0;
    int n = b[i].size();
    while(1){
      int t =C;
      int last;
      while(idx<n && t--){
        if(b[idx]-lastL>X){
          break;
        }
        last = b[idx];
      }
      if(last-lastidx<C){
        lastL+=X;
      }
      else{
        lastL = last;
      }

      if(idx==n)break;
      if(lastL>=x)break;
    }
  }
  return false;
}

signed main(){__
  int t,N,t1,t2,t3,d,c;
  cin>>C>>X>>T>>N;
  cin>>t1>>t2>>t3;
  for(int i =0;i<n;i++){
    cin>>d>>c;
    b[c-1].push_back(d);
  }
  sort(b[0].begin(),b[0].end());
  sort(b[1].begin(),b[1].end());
  sort(b[2].begin(),b[2].end());


  int l = 0,r = 1e12;
  while(l+1<r){
    int m = (l+r)>>1;
    if(check(m))
      r = m;
    else 
      l = m;
  }
  cout<<r<<endl;
}


