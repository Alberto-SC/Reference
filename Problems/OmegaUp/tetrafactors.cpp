#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int N = 5200000;
int divs[N+1];
unsigned long long  sieve(int n){
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; j += i)
			divs[j]++;
}

int main(){
	unsigned long long n,i =0,cont = 0;
	sieve(N);
	cin>>n;
	while(cont<n){
		if(divs[i] == 4)cont++;
		i++;
	}
	cout<<i-1;
}



