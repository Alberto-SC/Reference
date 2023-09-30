#include <bits/stdc++.h>
using namespace std;
struct bar{
  int a,b;
  bool z  =false;

};
int main(){
  bar b;
  bool &z = b.z;
  int &x =b.a;
  int &y =b.b;
  x = 3;
  y = 4;
  z= true;
  cout<<b.a<<" "<<b.b<<" "<<b.z<<endl;
  return 0;
}
