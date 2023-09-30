#include <bits/stdc++.h>
using namespace std;
vector<bool> primes(1000005,true);
void criba(int n){
	//cout<<"HOLA";
	primes[0] = false;
	primes[1] = false;
	for(int i = 4;i<=n;i+=2){
		primes[i] = false;
	}
	for(int i = 3;i*i<=n;i+=2){
		if(primes[i])
			for(int j = i*i;j<n;j+=2*i)
				primes[j] = false;
	}
}
int main(){
	int n,i,j;
	criba(1000000);
	while(true){
		cin>>n;
		if(!n) break;
		bool y = false;
		for( i = 1;i+i<=n;i++){	
			if(y) break;
			if(!primes[i])continue;
			for( j = n-1; j>= n/2;j--){
				if(!primes[j])continue;
				if(i+j == n){y = true;break;} 
				if(i+j < n) break;
			}

		}
		if(y) cout<<n<<" = "<<i-1<<" + "<<j<<endl;
		else cout<<"Goldbach's conjecture is wrong."<<endl;

	}

}