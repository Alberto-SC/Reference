#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<bool> sieve;
vector<lli> primos;

void criba(lli n){
	sieve.resize(n + 1, true);
	sieve[0] = sieve[1] = false;
	sieve[2] = true;
	primos.push_back(2);
	for(lli i = 4; i <= n; i += 2){
		sieve[i] = false;
	}
	lli limit = sqrt(n);
	for(lli i = 3; i <= n; i += 2){
		if(sieve[i]){
			primos.push_back(i);
			if(i <= limit){
				for(lli j = i * i; j <= n; j += 2 * i){
					sieve[j] = false;
				}
			}
		}
	}
}
bool primo(lli n){
	if(n<63246){
		return sieve[n];
	}
	else{
		for(lli &p: primos){
			if(p*p>n)break;
			if(n % p == 0)return false;
		}
		return true;
	}

}
int main(){
	ios_base::sync_with_stdio(0);
	lli n,t;
	cin>>t;
	criba(63246);
	while(t--){
		cin>>n;
		while(true){
			if(primo(n)) break;
			n++;
		}
		cout<<n<<endl;
	}
	return 0;
}