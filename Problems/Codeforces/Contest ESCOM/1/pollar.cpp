#include <bits/stdc++.h>
using namespace std;

long long int modularInverse(long long int a, long long int m){
	long long int r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
	while(r1){
		si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
		ri = r0 % r1, r0 = r1, r1 = ri;
	}
	if(r0 < 0) s0 *= -1;
	if(s0 < 0) s0 += m;
	return s0;
}
long long int gcd(long long int a, long long int b){
	long long int r;
	while(b != 0) r = a % b, a = b, b = r;
	return a;
}
long long int powerMod(long long int b, long long int e, long long int m){
	long long int ans = 1;
	b %= m;
	if(e < 0){
		b = modularInverse(b, m);
		e *= -1;
	}
	while(e){
		if(e & 1) ans = (ans * b) % m;
		e >>= 1;
		b = (b * b) % m;
	}
	return ans;
}
bool isPrimeMillerRabin(long long int n){
	if(n < 2) return false;
	if(n == 2) return true;
	long long int d = n - 1, s = 0;
	for(; !(d & 1); d >>= 1, ++s);
	for(int i = 0; i < 16; ++i){
		long long int a = 1 + rand() % (n - 1);
		long long int m = powerMod(a, d, n);
		if(m == 1 || m == n - 1) goto exit;
		for(int k = 0; k < s; ++k){
			m = m * m % n;
			if(m == n - 1) goto exit;
		}
		return false;
		exit:;
	}
	return true;
}

long long int getFactor(long long int n){
	long long int a = 1 + rand() % (n - 1);
	long long int b = 1 + rand() % (n - 1);
	long long int x = 2, y = 2, d = 1;
	while(d == 1){
		x = x * (x + b) % n + a;
		y = y * (y + b) % n + a;
		y = y * (y + b) % n + a;
		d = gcd(abs(x - y), n);
	}
	return d;
}

map<long long int, int> fact;
void factorizePollardRho(long long int n, bool clean = true){
	if(clean) fact.clear();
	while(n > 1 && !isPrimeMillerRabin(n)){
		long long int f = n;
		for(; f == n; f = getFactor(n));
		n /= f;
		factorizePollardRho(f, false);
		for(auto & it : fact){
			while(n % it.first == 0){
				n /= it.first;
				++it.second;
			}
		}
	}
	if(n > 1) ++fact[n];
}
int main(){
    long long n = 1000000000000;
    factorizePollardRho(n,true);
    for(auto it = fact.cbegin(); it != fact.cend(); ++it)
    cout << it->first << " " << it->second << "\n";

}