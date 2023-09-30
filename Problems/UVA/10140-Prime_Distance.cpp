#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
vector<bool> isPrime;
void criba(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]){
			primes.push_back(i);
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i)
					isPrime[j] = false;
		}
	}
}

bool prime(long long n){
	if(n<1000000)return isPrime[n];
	for(long long &p: primes){
		if(p*p >n)break;
		if(n%p== 0)return false;
	}
	return true;
}
int main(){
	long long l,u;
	criba(1000000);
	while(cin>>l>>u){	
	bool y = false;
	long long primeAnt,m = 1000,mx = -10;
	long long mini = -1,minj = -1,maxi = -1,maxj = -1;
	for(int i = l;i<=u;i++){
		//cout<<i<<endl;
		if(!y){
			if(prime(i))y = true,primeAnt = i;
		}
		else{	
		//cout<<primeAnt<<endl;
		if(prime(i)){
			if(i-primeAnt< m){
				m = i-primeAnt;
				mini = primeAnt;
				minj = i;
			}
			if(i-primeAnt>mx){
				mx = i-primeAnt;
				maxi = primeAnt;
				maxj = i;
			}
			primeAnt = i;
		}
		}
	}
	if(minj == -1)cout<<"There are no adjacent primes."<<endl;
	else
	cout<<mini<<","<<minj<<" are closest, "<<maxi<<","<<maxj<<" are most distant."<<endl;
	}
	return 0;
}