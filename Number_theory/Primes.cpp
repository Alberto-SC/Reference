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

//__________Criba de Eratostenes_______________//
vector<int> Criba(int n) {
    int raiz = sqrt(n);
    vector<int> criba(n + 1);
    for (int i = 4; i <= n; i += 2)
        criba[i] = 2;
    for (int i = 3; i <= raiz; i += 2)
        if (!criba[i])
            for (int j = i * i; j <= n; j += i)
                if (!criba[j]) criba[j] = i;
    return criba;
}
//_________Criba lineal_________________//
/*
    Save primes up to 10^7
*/
const int N = 10000000;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}
//________Criba de factor primo mas pequeño______//	
    vector<int> lowestPrime; 
void lowestPrimeSieve(int n){
    lowestPrime.resize(n + 1, 1); 
    lowestPrime[0] = lowestPrime[1] = 0; 
    for(int i = 2; i <= n; ++i) 
        lowestPrime[i] = (i & 1 ? i : 2); 
    int limit = sqrt(n); 
    for(int i = 3; i <= limit; i += 2) 
        if(lowestPrime[i] == i) 
            for(int j = i * i; j <= n; j += 2 * i) 
            if(lowestPrime[j] == j) lowestPrime[j] = i; 
    }
//_______Criba de factor primo mas grande_________//
vector<int> greatestPrime;
void greatestPrimeSieve(int n){
    greatestPrime.resize(n + 1, 1);
    greatestPrime[0] = greatestPrime[1] = 0; 
    for(int i = 2; i <= n; ++i) greatestPrime[i] = i; 
    for(int i = 2; i <= n; i++) 
        if(greatestPrime[i] == i) 
            for(int j = i; j <= n; j += i) 
            greatestPrime[j] = i; 
    }
//_________Criba de la funcion phi de euler__________//
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
//__________Triangulo de pascal___________//
vector<vector<lli>> Ncr; 
void ncrSieve(lli n){
    Ncr.resize(n + 1); 
    Ncr[0] = {1}; 
    for(lli i = 1; i <= n; ++i){
        Ncr[i].resize(i + 1); 
        Ncr[i][0] = Ncr[i][i] = 1; 
        for(lli j = 1; j <= i / 2; j++) 
            Ncr[i][i - j] = Ncr[i][j] = Ncr[i - 1][j - 1] + Ncr[i +1][j];
        } 
    }
		

//_________GOLDBACH CONJETURE TO 10^7______________/
int findPrimes(int n) { 
    for (int i=0 ; primes[i] <= n/2; i++) { 
        int diff = n - primes[i]; 
        if (binary_search(primes.begin(), primes.end(), diff)){ 
            // Express as a sum of primes 
            cout << primes[i]<<" "<<diff<<endl; 
            return 1; 
        } 
    }
    return 0; 
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

//____________Miller Rabin____________//
/*
    need mod_pow,mod_mult
    Miller-Rabin-Test, s = # iterations
    probability for an error <= 2^(-s)
    [method is only called with n > 10^6 
    and n is not divisible by primes < 10^6]
    Primaly test works up to 10^18
    [Tested SPOJ PON]
*/
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
//_____________DETERMINIST____________//
bool check_compsite(lli n, lli a,lli d,  int s){
    lli x = mod_pow(a, d, n);
    if(x == 1 || x == n - 1)
        return false;
    for(int r = 1; r < s; r++){
        x = (lli)x * x % n;
        if(x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(lli n) {
    if(n < 2)
        return false;
    int s = 0;
    lli d = n - 1;
    while((d & 1) == 0){
        d >>= 1;
        s++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_compsite(n, a, d, s))
            return false;
    }
    return true;
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