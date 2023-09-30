#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

vector<int> primesSieve(int n){
	vector<bool> is(n+1, true);
	vector<int> primes = {2};
	is[0] = is[1] = false;
	for(int i = 4; i <= n; i += 2) is[i] = false;
	for(int i = 3; i <= n; i += 2){
		if(is[i]){
			primes.push_back(i);
			if((long long)i*i <= n)
				for(int j = i*i; j <= n; j += 2*i)
					is[j] = false;
		}
	}
	return primes;
}


int main(){
	auto primes = primesSieve(1000001);
	int t; cin >> t;
	while(t--){
		int i,j; cin >> i >> j;
		auto beg = lower_bound(primes.begin(), primes.end(), i);
		auto end = lower_bound(primes.begin(), primes.end(), j);
		if(*end == j) end++;
		cout << distance(beg, end) << endl;
	}

	return 0;
}
