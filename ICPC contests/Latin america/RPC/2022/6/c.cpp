#include <iostream>
using namespace std ;
using ll = long long ;
const ll MOD = 1000000007 ;
ll expo(ll a, ll n, ll MOD) {
   n %= (MOD-1) ;
   ll r = 1 ;
   while (n) {
      if (n & 1)
         r = (r * a) % MOD ;
      a = (a * a) % MOD ;
      n >>= 1 ;
   }
   return r ;
}


ll inv(ll a, ll MOD) {
   a %= MOD ;
   return expo(a, MOD-2, MOD) ;
}
int main() {
   ll a, b, n ;
   cin >> a >> b >> n ;
   ll r = (a*a-b*b) % MOD ;
   ll s = (a*a+b*b) % MOD ;
   ll t = 2*a*b % MOD ;
   cout<<r<<" "<<s<<" "<<t<<endl;
   // ll x = -1 ;
   // ll y = 0 ;
   // ll z = 1 ;
   // n++ ;
   // while (n != 0) {
   //    if (n & 1) {
   //       ll x2 = (x*r-y*t) % MOD ;
   //       ll y2 = (x*t+y*r) % MOD ;
   //       z = z*s % MOD ;
   //       x = x2 ;
   //       y = y2 ;
   //    }
   //    ll r2 = (r*r-t*t) % MOD ;
   //    ll t2 = (2*r*t) % MOD ;
   //    s = s*s % MOD ;
   //    r = r2 ;
   //    t = t2 ;
   //    n >>= 1 ;
   // }
   // ll res = x * inv(z, MOD) % MOD ;
   // res = (res + MOD) % MOD ;
   // cout << res << endl ;
}