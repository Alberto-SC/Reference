#include <iostream>
#include <cmath>
const double PI  =3.141592653589793238463;
using namespace std;
//Formula de stirling
int main(){
	int n;
	cin>>n;
	if(n == 0||n==1||n==2||n==3){
		cout<<n<<"! tiene 1 digitos";
	}
	else{	
	unsigned long long r = ceil(log10(sqrt(2*PI*n))   + n*(log10(n/exp(1))));
	cout<<n<<"! tiene "<<r<<" digitos";
	}
}