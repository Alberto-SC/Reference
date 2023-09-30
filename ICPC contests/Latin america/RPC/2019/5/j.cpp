#include <bits/stdc++.h>
using namespace std ;
int main() {
    int m;
    cin>>m;
    long long n=m;
    long long  suma=n;
    long long  sumleft=m;
    for (long long x=m+1; ; x++){
      long long  s = 2 * sumleft + x ;
      while (suma < s)
         suma += ++n;
      if (suma == s) {
         cout <<m<<" "<<x<<" "<<n<<endl ;
         return 0 ;
      }
      sumleft += x ;
    }
    return 0;
}
