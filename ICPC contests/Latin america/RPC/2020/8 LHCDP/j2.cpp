#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long int lli;

using namespace std;

const int N = 10000000;
int lp[N+1];
vector<int> primes;
void criba(){
    for(int i = 2;i<=N;i++){
        if(lp[i] == 0){
            lp[i] = i;
            primes.push_back(i);
        }
        for(int j = 0;j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N;j++)
            lp[i*primes[j]] = primes[j];
    }
}

lli multMod(lli a, lli b, lli n){
	lli x = 0;
	while(b){
		if(b & 1)	x = (x + a) % n;
		a = (a << 1) % n;
		b >>= 1;
	}
	return x;
}

lli gcd(lli a, lli b){
	lli r;
	while(b != 0) r = a % b, a = b, b = r;
	return a;
}

lli modularInverse(lli a, lli m){
	lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
	while(r1){
		si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
		ri = r0 % r1, r0 = r1, r1 = ri;
	}
	if(r0 < 0) s0 *= -1;
	if(s0 < 0) s0 += m;
	return s0;
}

lli powerMod(lli a, lli n, lli m){
	lli x = 1;
	while(n){
		if(n & 1)	x = multMod(x, a, m);
		a = multMod(a, a, m);
		n >>= 1;
	}
	return x;
}

bool isPrimeMillerRabin(lli n){
	if(n < 2) return false;
	if(!(n & 1)) return n == 2;
	lli d = n - 1, s = 0;
	for(; !(d & 1); d >>= 1, ++s);
	for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
		if(n == a) return true;
		lli m = powerMod(a, d, n);
		if(m == 1 || m == n - 1) continue;
		int k = 0;
		for(; k < s; ++k){
			m = m * m % n;
			if(m == n - 1) break;
		}
		if(k == s) return false;
	}
	return true;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
lli aleatorio(lli a, lli b){
	std::uniform_int_distribution<lli> dist(a, b);
	return dist(rng);
}
lli getFactor(lli n){
	lli a = aleatorio(1, n - 1), b = aleatorio(1, n - 1);
	lli x = 2, y = 2, d = 1;
	while(d == 1){
		x = x * (x + b) % n + a;
		y = y * (y + b) % n + a;
		y = y * (y + b) % n + a;
        if(x > y)
			d = gcd(x - y, n);
		else
			d = gcd(y - x, n);
	}
	return d;
}

lli random(lli a, lli b) {
    lli intervallLength = b - a + 1;
    int neededSteps = 0;
    lli base = RAND_MAX + 1LL;
    while(intervallLength > 0){
    	intervallLength /= base;
    	neededSteps++;
    }
    intervallLength = b - a + 1;
    lli result = 0;
    for(int stepsDone = 0; stepsDone < neededSteps; stepsDone++){
        result = (result * base + rand());
    }
    result %= intervallLength;
    if(result < 0) result += intervallLength;
    return result + a; 
}

bool witness(lli a, lli n) {
	// check as in Miller Rabin Primality Test described
    lli u = n-1;
    int t = 0;
    while (u % 2 == 0) {
        t++;
        u /= 2;
    }
    lli next = powerMod(a, u, n);
    if(next == 1)return false;
    lli last;
    for(int i = 0; i < t; i++) {
    	last = next;
        next = multMod(last, last, n);//(last * last) % n;
        if (next == 1){
        	return last != n - 1;
        }
    }
    return next != 1;
}


bool isPrime(lli n, int s) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for(int i = 0; i < s; i++) {
        lli a = random(1, n-1);
        if (witness(a, n)) return false;
    }
    return true;
}

map<lli, int> fact;
void factorizePollardRho(lli n, bool clean = true){
	if(clean) fact.clear();
	while(n > 1 && !isPrime(n,20)){
		lli f = n;
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
	fast_io
	criba();
	int t; cin >> t;
	while(t--){
		lli n; cin >> n;
		factorizePollardRho(n);
		for(auto v:fact){
			for(int i=0; i<v.second; i++){
				cout << v.first << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}