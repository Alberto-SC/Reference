#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

int fact(ull a){
	int cont = 0,sigma0 = 1;
	while((a&1) == 0){
		a = a >> 1;
		cont++;
	}
	if(cont)sigma0*=(cont+1);
	ull i = 3;
	while(i*i<=a){
		cont = 0;
		while(a%i== 0){
			cont ++;
			a/=i;
		}
		if(cont)sigma0 *= cont+1;
		i+=2;
	}
	if(a>1)sigma0 *= 2;
	return sigma0;
}
int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0);  
	ull a,b;
	cin>>a>>b;
	cout<<fact(__gcd(a,b))<<endl;
}