#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

int main(){
  ld N;
  cin>>N;
  ld minD= sqrt(6)-sqrt(2);
  ld minL= 2+ 4/minD;
  ld res = (minL*N)*(minL*N);
  cout<< fixed<< setprecision(5)<<res<<"\n";
  return 0;
}