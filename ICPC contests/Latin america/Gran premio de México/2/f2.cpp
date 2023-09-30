#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define x real()
#define y imag()

typedef int T;
typedef complex<T> pt;

T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}

// 0 if is colinear (or are in the line AB), >0 if is left turn , <0 if is a right turn 
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

signed main(){__
  int n;
  cin>>n;
  vector<pt> p(n);
  for(int i = 0;i<n;i++){
    T px,py;
    cin>>px>>py;
    p[i] = pt(px,py);
  }


  int ans = 0;
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      for(int k = j+1;k<n;k++){
        for(int l = k+1;l<n;l++){
         if(orient(p[i],p[j],p[k])==0)continue;
         if(orient(p[i],p[j],p[l])==0)continue;
         if(orient(p[j],p[k],p[l])==0)continue;
         if(orient(p[i],p[k],p[l])==0)continue;
         ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}