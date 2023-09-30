#include <bits/stdc++.h>
using namespace std;

int N = 1000007;
vector<int> lp(N+1);
vector<int> primes;

void sieve(){
	for(int i = 2;i<=N;i++){
		if(!lp[i]){
			lp[i] = i;
			primes.push_back(i);
		}
		for(int j = 0;j<primes.size() && primes[j]*i<=N && primes[j]<=lp[i];j++){
			lp[primes[j]*i] = primes[j];
		}
	}
}

const int mod = 1e9+7;

int mod_pow(int a,int b){
	int x= 1;
	while(b){
		if(b&1)(x*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return x;
}


int main() {
	int n,k;
	sieve();
	cin >> n>>k; 
	vector<int> nums(n);
	int X = 0;
	for(auto &c:nums){
		cin>>c;
		while(c>1){
			X++;
			c/=lp[c];
		}
	}

	cout<<mod_pow(k,X)<<endl;

}