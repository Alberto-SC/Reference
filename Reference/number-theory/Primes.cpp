

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

//_______Neds___________//
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


//_________Criba de la funcion phi de euler__________//
bool is_composite[MAXN];
int phi[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	phi[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			phi[i] = i - 1;					//i is prime
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
			}
		}
	}
}

/*Criba para hallar todos los valores de 1-n de una 
función multiplicativa*/

int N = 10000007;
vector<int> F(N+1);   //funcion multiplicativa evaluada en i
int g(int p, int a){
	//Ejemplo para la phi de euler
	return power(p, a - 1) * (p - 1);
}

vector<int> sieve(int N){
	vector<int> primes;
	vector<int> lp(N+1);  //factor primo mas pequeño de i
	vector<int> cnt(N+1); //exponente del primo mas pequeño de i
	vector<int> pot(N+1); //pow(lp[i], cnt[i])
	F[1] = 1;
	for(int i = 2; i <= N; ++i){
		if(lp[i] == 0){
			primes.push_back(i);
			lp[i] = i;
			F[i] = g(i, 1);
			cnt[i] = 1;
			pot[i] = i;
		}
		for(int p : primes){
			int d = i * p;
			if(d > N) break;
			lp[d] = p;
			if(p == lp[i]){
				F[d] = F[i / pot[i]] * g(p, cnt[i]+1);
				cnt[d] = cnt[i] + 1;
				pot[d] = pot[i] * p;
				break;
			}else{
				F[d] = F[i] * F[p];
				cnt[d] = 1;
				pot[d] = p;
			}
		}
	}
	return f;
}


vector<int> Phi; 
void phiSieve(int n){ 
    Phi.resize(n + 1); 
    for(int i = 1; i <= n; ++i) 
        Phi[i] = i; 
    for(int i = 2; i <= n; ++i) 
        if(Phi[i] == i) 
            for(int j = i; j <= n; j += i) 
                Phi[j] -= Phi[j] / i; 
}
//_____________****************************________//
vector<int> Mu; 
void muSieve(int n){
    Mu.resize(n + 1, -1); 
    Mu[0] = 0, Mu[1] = 1; 
    for(int i = 2; i <= n; ++i) 
        if(Mu[i]) 
            for(int j = 2*i; j <= n; j += i) 
                Mu[j] -= Mu[i];
}

//_________bLOCK SIEVE____________//
int count_primes(int n) {
    const int S = 10000;
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }
    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

//___________________PHI DE EULER_______________________//
//numero de numeros menores a n coprimos con n
int phi (int n){
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if(n %i==0){
			while(n %i==0)
			n /= i;
			result -= result / i;
	}
	if (n > 1)
	result -= result / n;
	return result;
}

//____________Count divisors in n^1/3____________//
/*
    Need miller rabin,criba(),primes[],lp[],N= 10^6
    [Tested Codeforces GYM GCPC-15 F-Divisions]
*/
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
	for(int i = 0; i < primes.size(); i++){
		if(n == 1)break;
		int p = primes[i];
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
	else if(isPrime(n,20))return ans * 2; // second case
	else if(isSquare(n))return ans * 3; // third case but with p == q
	else return ans * 4; // third case with p != q
} 

// arr is a primeFact of n with a pair <prime,exponent>
void generateDivisors(int curIndex, int curDivisor, vector<pair<int,int>>& arr){  
    if (curIndex == arr.size()) { 
        cout << curDivisor << ' '; 
        return; 
    } 
  
    for (int i = 0; i <= arr[curIndex].y; ++i) { 
        generateDivisors(curIndex + 1, curDivisor, arr); 
        curDivisor *= arr[curIndex].x; 
    } 
} 


//_________Prime Factors__________//
map<lli,lli> fact;
void trial_division4(lli n) {
    for (lli d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            fact[d]++;
            n /= d;
        }
    }
}
void trial_division2(lli n) {
    while (n % 2 == 0) {
        fact[2]++;
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            fact[d]++;
            n /= d;
        }
    }
    if (n > 1)
        fact[n]++;
}
/*
    Pollard Method p-1
*/
lli pollard_p_1(lli n){
	int b = 13;
	int q[] = {2, 3, 5, 7, 11, 13};
	lli a = 5% n;
	for (int j = 0; j <10; j ++){
		while (__gcd(a, n)!= 1){
			mod_mult (a, a, n);
			a+= 3;
			a%= n;
		}
		for (int i = 0; i<6; i ++){
			int qq = q [i];
			int e =  floor(log((double) b) / log((double) qq));
			lli aa = mod_pow(a, mod_pow (qq, e, n), n);
			if (aa == 0)
				continue;			
		    lli g = __gcd (aa-1, n);
			if (1 <g && g <n)
				return g;
		}

	}
	return 1;
}

/*
    Pollard rho
*/ 
lli pollard_rho (lli n, unsigned iterations_count = 100000){
	lli b0 = rand ()% n,b1 = b0,g;
	mod_mult (b1, b1, n);
	if (++b1 == n)
		b1 = 0;
	g = __gcd(abs(b1 - b0), n);
	for (unsigned count = 0; count <iterations_count && (g == 1 || g == n); count ++){
		mod_mult (b0, b0, n);
		if (++ b0 == n)
			b0 = 0;
		mod_mult (b1, b1, n);
		++ b1;
		mod_mult (b1, b1, n);
		if (++ b1 == n)
			b1 = 0;
		g = __gcd(abs(b1 - b0), n);
	}
	return g;
}
lli pollard_bent (lli n, unsigned iterations_count = 19){ 
	lli b0 = rand ()% n,
		b1 = (b0 * b0 + 2)% n,
		a = b1;
	for (unsigned iteration = 0, series_len = 1; iteration <iterations_count; iteration ++, series_len *= 2){
		lli g = __gcd(b1-b0, n);
		for (unsigned len = 0; len <series_len && (g == 1 && g == n); len ++){
			b1 = (b1 * b1 + 2)% n;
			g = __gcd(abs (b1-b0), n);
		}
		b0 = a;
		a = b1;
		if (g != 1 && g != n)
			return g;
	}
	return 1;
}
/*
    Pollard monte Carlo
*/ 
lli pollard_monte_carlo (lli n, unsigned m = 100){
	lli b = rand ()% (m-2) + 2;
	lli g = 1;
	for (int i = 0; i <100 && g == 1; i++){
		lli cur = primes[i];
		while (cur <= n)
			cur *= primes[i];
		cur /= primes[i];
		b = mod_pow (b, cur, n);
		g = __gcd(abs (b-1), n);
		if (g == n)
			g = 1;
	}
	return g;
}
lli prime_div_trivial (lli n){
	if (n == 2 || n == 3)
		return 1;
	if (n <2)
		return 0;
	if (!n&1)
		return 2;
	lli pi;
	for (auto p:primes){
		if (p*p >n)
			break;
		else
			if (n% p == 0)
				return p;
	}
	if (n <1000*10000)
		return 1;
	return 0;
}

lli ferma (lli n){
	lli	x = floor(sqrt((double)n)),y = 0,r = x * x - y * y - n;
	for (;;)
		if (r == 0)
			return x != y? x*y: x + y;
		else
			if (r> 0){
				r-= y + y + 1;
				++y;
			}
			else{
				r+= x + x + 1;
				++x;
			}
}
lli mult(lli a, lli b, lli mod) {
    return (lli)a * b % mod;
}

lli f(lli x, lli c, lli mod) {
    return (mult(x, x, mod) + c) % mod;
}
lli brent(lli n, lli x0=2, lli c=1) {
    lli x = x0;
    lli g = 1;
    lli q = 1;
    lli xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = __gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = __gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}
void factorize (lli n){
    if (isPrime(n,20))
        fact[n]++;
    else{
        if (n <1000 * 1000){
            lli div = prime_div_trivial(n);
            fact[div]++;
            factorize(n / div);
        }
        else{
            lli div;
            // Pollard’s fast algorithms come first
            div = pollard_monte_carlo(n);
            if (div == 1)
                div = brent(n);
            if (div == 1)
                div = pollard_rho (n),cout<<"USE POLLAR_RHO\n";
            if (div == 1)
                div = pollard_p_1 (n),cout<<"USE POLLARD_P_1\n";
            if (div == 1)
                div = pollard_bent (n),cout<<"USE POLLARD_BENT\n";
            if (div == 1)
                div = ferma (n);
            // recursively process the found factors
            factorize (div);
            factorize (n / div);
        }
    }
}
// Get prime factors of a number in time O(log(n)) with precompute array of lowest factor of a number up to 10^7 complexity of precalc is O(nlognlogn)
// uses lowestprime
vector<int> facts;
void factorizeLog(lli n){
    while(n>1){
        facts.push_back(lowestPrime[n]);
        n/=lowestPrime[n];
    }
}
int main(){
	lli n,i,j;
    cin>>n;
	criba();
    // for(int i = 0;i<N;i++){
    //     cout<<primes[i]<<" ";
    // }
    // cin>>n;
    // if(!findPrimes(n))cout<<-1<<endl;
    // cout<<countDivisors(n);
    // factorize(n);
    lowestPrimeSieve(10000000);
    factorize(n);
    factorizeLog(n);
    for(auto c:facts)cout<<c<<" ";
    cout<<endl;
    // cout<<fact.size();
    for(auto c: fact)cout<<c.first<<"^"<<c.second<<" ";
}