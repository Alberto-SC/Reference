/**
 * Author: Various / Alberto Silva
 * Description: Get the nth fibonacci number, various methods. 
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli M = 100000000000000000; // modulo

// Matrix exponentiation method
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
void power(lli F[2][2], lli n) { 
  if( n == 0 || n == 1) 
      return; 
  lli M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
lli fibonacciMatrix(lli n){  
  lli F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 


// Aproximate formula
lli fibonacciApproximation(lli n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 
  
// Recursive 

map<lli, lli> F;
lli fibonacci(lli n) {
	if (F.count(n)) return F[n];
	lli k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (fibonacci(k)*fibonacci(k) + fibonacci(k-1)*fibonacci(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (fibonacci(k)*fibonacci(k+1) + fibonacci(k-1)*fibonacci(k)) % M;
	}
}


// Exclude from here 
int  main(){
    lli n;
    F[0]=F[1]=1;
    cin>>n;

    cout<<fibonacciApproximation(n)<<endl;
    cout<<fibonacciMatrix(n)<<endl;
    cout<<fibonacci(n-1)<<endl;
    return 0;
}