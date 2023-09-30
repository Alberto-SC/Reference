#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
unsigned long long  sigma0(unsigned long long n){
	unsigned long long sigma0 = 1,c = 3,copy = n,cont = 0;
	while (n%2 == 0) { 
        cont++; 
        n = n/2; 
    } 
    sigma0*= (cont+1);
		while(n != 1 && c <= sqrt(copy)+1){
			cont = 0;
			while(n % c == 0){
				cont++;
				n = n /c;
			}
			sigma0*= (cont+1);
			c+=2;
		}
	if(n>2)sigma0*= 2;
	
	return sigma0;
}

int main(){
	unsigned long long n;
	cin>>n;
	cout<<sigma0P(n);

}