#include <iostream>
using namespace std ;
using ll = long long ;
ll gcd(ll a, ll b) {
   if (b < a)
      swap(a, b) ;
   if (a == 0)
      return b ;
   return gcd(b % a, a) ;
}
void failit(const char *s) {
   cerr << s << endl ;
}
void reduce(ll &a, ll &b) {
   ll g = gcd(abs(a), b) ;
   a /= g ;
   b /= g ;
}
int main() {
   ll a, b, n ;
   cin >> a >> b >> n ;
   if (gcd(a, b) != 1)
      failit("A and B are not relatively prime") ;
   if ((b & 1) == 0 && n >= (a + b - 3) / 2)
      failit("N is too high; hits a corner") ;
   ll x = 0 ;
   ll y = b ;
   n++ ;
   while (n--) {
      ll dx = 2 * a - x % (2 * a) ;
      ll dy = 2 * b - y % (2 * b) ;
      if (dx == dy)
         failit("Hit a corner") ;
      ll d = min(dx, dy) ;
      x = (x + d) % (4 * a) ;
      y = (y + d) % (4 * b) ;
   }
   x -= a ;
   y -= b ;
   if (x > a)
      x = 2 * a - x ;
   if (y > b)
      y = 2 * b - y ;
   reduce(x, a) ;
   reduce(y, b) ;
   cout << x << " " << a << " " << y << " " << b << endl ;
}