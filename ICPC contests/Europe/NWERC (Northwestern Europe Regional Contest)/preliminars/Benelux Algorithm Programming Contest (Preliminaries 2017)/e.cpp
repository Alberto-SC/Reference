#include <bits/stdc++.h>
using namespace std;
const string ERROR{"error"};
long long int mod  = 1e9 + 7;
long long int maxa = 1ll << 60;
int main() {
	int n;
	long long a = 1;
	cin >> n;
	vector<long long> b(n);
	for(auto &x : b) cin>>x;
	bool posE = true;
	for(auto x : b) {
		a *= 2;
		if(posE) 
			if(x > a) 
				return cout<<"error\n",0;
		a -= x;
		if(a >= maxa) 
			posE = false;
		if(!posE) a = (a % mod + mod) % mod;
	}
	cout << a % mod << "\n";
}
