#include <bits/stdc++.h>
using namespace std;
typedef  long long int lli;
const int N = 1000000;
int lp[N+1];
vector<int> pr;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
lli mod_mult(lli a, lli b, lli mod){
	lli x = 0;
	while(b){
		if(b & 1)	x = (x + a) % mod;
		a = (a << 1) % mod;
		b >>= 1;
	}
	return x;
}

lli mod_pow(lli a, lli n, lli mod){
	lli x = 1;
	while(n){
		if(n & 1)	x = mod_mult(x, a, mod);
		a = mod_mult(a, a, mod);
		n >>= 1;
	}
	return x;
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

// checks whether a is a witness that n is not prime, 1 < a < n
bool witness(lli a, lli n) {
	// check as in Miller Rabin Primality Test described
    lli u = n-1;
    int t = 0;
    while (u % 2 == 0) {
        t++;
        u /= 2;
    }
    lli next = mod_pow(a, u, n);
    if(next == 1)return false;
    lli last;
    for(int i = 0; i < t; i++) {
    	last = next;
        next = mod_mult(last, last, n);//(last * last) % n;
        if (next == 1){
        	return last != n - 1;
        }
    }
    return next != 1;
}
 
// Miller-Rabin-Test, s = # iterations
// probability for an error <= 2^(-s)
// [method is only called with n > 10^6 
// and n is not divisible by primes < 10^6]
bool millerRabin(lli n, int s) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for(int i = 0; i < s; i++) {
        lli a = random(1, n-1);
        if (witness(a, n)) return false;
    }
    return true;
}

// uses Miller-Rabin
bool isPrime(lli val){
	return millerRabin(val, 20);
}
bool isSquare(lli val){
	lli lo = 1, hi = val;
	while(lo <= hi){
		lli mid = lo + (hi - lo) / 2;
		lli tmp = (val / mid) / mid; // be careful with overflows!!
		if(tmp == 0)hi = mid - 1;
		else if(mid * mid == val)return true;
		else if(mid * mid < val)lo = mid + 1;
	}
	return false;
}
lli countDivisors(lli n) {   
    lli ans = 1;
	for(int i = 0; i < pr.size(); i++){
		if(n == 1)break;
		int p = pr[i];
		if(n % p == 0){ // checks whether p is a divisor of n
			int num = 0;
			while(n % p == 0){
				n /= p;
				++num;
			}
			// p^num divides initial n but p^(num + 1) does not divide initial val
			// => p can be taken 0 to num times => num + 1 possibilities!!
			ans *= num + 1;
		}
	}
    if(n == 1)return ans; // first case
	else if(isPrime(n))return ans * 2; // second case
	else if(isSquare(n))return ans * 3; // third case but with p == q
	else return ans * 4; // third case with p != q
} 

int main(){
    lli n;
    cin>>n;
    criba();
    cout<<countDivisors(n);
    return 0;
}