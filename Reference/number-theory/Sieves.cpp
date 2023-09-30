/**
 * Author: Alberto Silva 
 * License: CC0
 * Description: Prime sieve for generating all primes smaller than LIM.
 * Status: Stress-tested
 * Details: Different implementations ,linear sieveDespite its n log log n complexity, segmented sieve is still faster
 * - Linear sieve: , get primes in range [1-n] with complexity O(n) using the lowest prime factor of each number wich is also saved in lp[i] 
 * - Greatest prime sieve: , get the greatest prime factor of each numberin in range [1,n] with complexity $O(n logn)$ 
 * - Segmented sieve: , get primes in range[L,R] with complexity O(max(sqrt(R)log(sqrt(R)),R-L)) ??? ;
 * - Phi sieve: , get the number of coprimes of each number in range [1,n] with complexity $O(n logn)$ \emph{Euler's $\phi$} function is defined as $\phi(n):=\#$ of positive integers $\leq n$ that are coprime with $n$.
 * $\phi(1)=1$, $p$ prime $\Rightarrow \phi(p^k)=(p-1)p^{k-1}$, $m,n$ coprime $\Rightarrow \phi(mn)=\phi(m)\phi(n)$.
 * If $n=p_1^{k_1}p_2^{k_2} ... p_r^{k_r}$ then $\phi(n) = (p_1-1)p_1^{k_1-1}...(p_r-1)p_r^{k_r-1}$.
 * $\phi(n)=n \cdot \prod_{p|n}(1-1/p)$.
 *
 * $\sum_{d|n} \phi(d) = n$, $\sum_{1\leq k \leq n, \gcd(k,n)=1} k = n \phi(n)/2, n>1$
 *
 * \textbf{Euler's thm}: $a,n$ coprime $\Rightarrow a^{\phi(n)} \equiv 1 \pmod{n}$.
 *
 * \textbf{Fermat's little thm}: $p$ prime $\Rightarrow a^{p-1} \equiv 1 \pmod{p}$ $\forall a$.
 * Also is one of the fastest sieve get all primes in range [1-n] with n = $1^9$ in 8.62s and for 
 * n = $1^8$ in 0.76s .in adition you have also the sum of all primes in range [L,R] and the number of primes in range [L,R]
 */

// Also gets sieve of function $\mu$
const int N = 1000007;
vector<int> m(N+1);
void sieve(){
	vector<int> lp(N+1);
	vector<int> primes;
	m[1]= 1;
	for(int i = 2;i<=N;i++){
		if(lp[i]== 0){
			primes.push_back(i);
			lp[i]= i;
			m[i] = -1;
		}
		for(int j  = 0;j<primes.size()&& primes[j]<=lp[i] && primes[j]*i<=N;j++){
			lp[primes[j]*i] = primes[j];
			if(lp[i]==primes[j])m[primes[j]*i]= 0;
			else m[primes[j]*i] = m[primes[j]]*m[i]; 
		}
	}
}

// Just get primes and lowest prime factor of each number
const int N = 10000000;
int lp[N+1];
vector<int> primes;
void sieve(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j){
            lp[i * primes[j]] = primes[j];
            if(i%primes[j]==0)break;
        }
    }
}

// Sieve with bitset is faster than the sieve with vector also gets the sum of all primes in range [1,n] and the number of primes in range [1,n]
const int NMAX = 100000000;
signed main() {
    bitset<NMAX / 2> bits;
    bits.set();
	auto sum = 2LL;
	int cnt = 1;
    for (int i = 3; i / 2 < bits.size(); i = 2 * bits._Find_next(i / 2) + 1) {
        sum += i;
        ++cnt;
        for (auto j = (int64_t) i * i / 2; j < bits.size(); j += i) 
            bits[j] = 0;
    }
	cout << "sum = " << sum << endl;
	cout << "cnt = " << cnt << endl;
	return 0;
}

// Greatest prime sieve
vector<int> gp;
void greatestPrimeSieve(int n){
    gp.resize(n + 1, 1);
    gp[0] = gp[1] = 0; 
    for(int i = 2; i <= n; ++i) gp[i] = i; 
    for(int i = 2; i <= n; i++) 
        if(gp[i] == i) 
            for(int j = i; j <= n; j += i) 
            	gp[j] = i; 
    }


vector<int> PrimesInRange;
void SegmentedSieve(int l ,int r) {
    auto sum = l<=2?2:0;
    if(l<=2)PrimesInRange.push_back(2);
    int cnt = 1;
 
    const int S = round(sqrt(r));
    vector<char> sieve(S + 1, true);
    vector<array<int, 2>> cp;
    for (int i = 3; i <= S; i += 2) {
        if (!sieve[i])
            continue;
        cp.push_back({i, (i * i - 1) / 2});
        for (int j = i * i; j <= S; j += 2 * i){
            sieve[j] = false;
        }
    }
    vector<char> block(S);
    int high = (r - 1) / 2;
    int x = l/S;
    int L = (x/2)*S;
    for(auto &i:cp){
        int p = i[0],idx = i[1];
        if(idx>L){
            i[1]-=L;
        }
        else{
            int X = (L-idx)/p;
            if((L-idx)%p)X++;
            if(X>=1 && idx<=L)
                i[1] = (idx+(p*X))-L;
        }
    }
    for (int low =(x/2)*S; low <= high; low += S) {
        fill(block.begin(), block.end(), true);
        for (auto &i : cp) {
            int p = i[0], idx = i[1];
            for (; idx < S; idx += p){
                block[idx] = false;
            }
            i[1] = idx - S;
        }
        if (low == 0)
            block[0] = false;
        for (int i = 0; i < S && low + i <= high; i++){
            if (block[i] && (((low+i)*2)+1)>=l){
                // push the primes here if needed 
                ++cnt, sum += (low + i) * 2 + 1;
            }
        }
    };
	// cout << "sum = " << sum << endl;
	// cout << "cnt = " << cnt << endl;
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