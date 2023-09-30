#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int get(int x,int up){
  int y = up/x;
  return x*y;
}

signed main(){__
  int T,n,a,b,c,d;
  cin>>T;
  while(T--){
    cin>>a>>b>>c>>d;
    int x = -1,y = -1;
    vector<int> divsa;
    vector<int> divsb;
    for(int i = 1;i*i<=a;i++){
      if(a%i ==0){
        divsa.push_back(i);
        if(a/i!= i)divsa.push_back(a/i);
      }      
    }
    for(int i = 1;i*i<=b;i++){
      if(b%i ==0){
        divsb.push_back(i);
        if(b/i!= i)divsb.push_back(b/i);
      }      
    }

    vector<int> divs;
    for(auto c:divsa){
      for(auto d:divsb){
        divs.push_back(c*d);
      }
    }
    

    for(int i = 0;i<divs.size();i++){
      int x1 = get(divs[i],c);
      
      if(x1>a){
        int y1 = get((a*b)/divs[i],d);
        if(y1>b){
          x = x1;
          y = y1;
        }
      }
      int y2 = get(divs[i],d);
      if(y2>b){
        int x2 = get((a*b)/divs[i],c);
        if(x2>a){
          x = x2;
          y = y2;
        }
      } 
    }
    cout<<x<<" "<<y<<endl; 

  }
  return 0;
}
