#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli M = 100000000000000000; // modulo
void multiply(lli F[2][2], lli M[2][2]) { 
  lli x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  lli y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  lli z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  lli w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
void power(lli F[2][2], lli n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  lli M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
lli fibF(lli n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 
  
lli fib(lli n){  
  lli F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 

map<lli, lli> F;
lli f(lli n) {
	if (F.count(n)) return F[n];
	lli k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}
a
int  main(){
    lli n;
    F[0]=F[1]=1;
    cin>>n;
    // cout<<fibF(n)<<endl;
    // cout<<fib(n)<<endl;
    cout<<f(n-1)<<endl;
    return 0;
}