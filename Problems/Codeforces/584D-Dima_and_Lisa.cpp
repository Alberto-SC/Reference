#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<bool> sieve(1000005,true);
vector<lli> primes;
void criba(lli n){
	sieve[0] = sieve[1] = false;
	for(int i = 4;i<=n;i+= 2)
		sieve[i] = false;
	primes.push_back(2);
	for(int i = 3;i*i<=n;i+= 2){
		if(sieve[i])
			for(int j = i*i;j<=n;j+= 2*i)
				sieve[j] = false;
	}
	for(int i = 0;i<=n;i++)
		if(sieve[i])primes.push_back(i);
}
bool primo(lli n){
	if(n<100000){
		return sieve[n];
	}
	else{
		for(lli  &p: primes){
			if(p*p>n)break;
			if(n % p == 0)return false;
		}
		return true;
	}

}
int main(){
	lli n;
	cin>>n;
	if(n == 3) {
        cout << 1 << endl << 3 << endl;
        return 0;
    }
    if(n == 5) {
        cout << 2 << endl << "3 2" << endl;
        return 0;
    }
	int j = sqrt(n);
	criba(1000000);
	//cout<<primes.size()<<endl;
	vector<int> ans;
	lli p = n-1;
	while(true){
		if(primo(p)) break;
		p--;
	}
	ans.push_back(p);
	n = n-p;
	lli a = 1, b = n - 1;
	while(a <= b){
		if(sieve[a] && sieve[b]) break;
		++a, --b;
	}
	if(b==0){	
		ans.push_back(a);
		cout<<2<<endl;
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}
	else{
		ans.push_back(b);	
		ans.push_back(a);
		cout<<3<<endl;
		cout<<ans[0]<<" "<<ans[1]<<" "<< ans[2]<<endl;		
	}
}
