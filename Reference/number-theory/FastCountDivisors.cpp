/**
 * Author: chilli, c1729, Simon Lindholm
 * Date: 2019-03-28
 * License: CC0
 * Source: Wikipedia, https://miller-rabin.appspot.com/
 * Description: Count the number of divisors of a large number
 * Time: $O(n^{\frac{1}{3}})$
 * Status: Stress-tested
 */

// #include "MillerRabin"
// #include "primes"


/*+    Need primes[],lp[],N= $10^6 $ */
#define lli long long
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
			// p^num divides initial n but $p^{num + 1}$ does not divide initial val
			// => p can be taken 0 to num times => num + 1 possibilities!!
			ans *= num + 1;
		}
	}
    if(n == 1)return ans; // first case
	else if(isPrime(n))return ans * 2; // second case
	else if(isSquare(n))return ans * 3; // third case but with p == q
	else return ans * 4; // third case with p != q
} 

using uint32 = unsigned int;
using uint64 = unsigned long long;
using uint128 = __uint128_t;
// compute $\sum_{i=1}^{n} \sigma (i)$ in $~O(n^{1/3})$ time.
// it is also equal to \sum_{i=1}^{n} floor(n / i)
// takes ~100 ms for n = 1e18 
uint128 sum_sigma0(uint64 n) {
	auto out = [n] (uint64 x, uint32 y) {
		return x * y > n;
	};
	auto cut = [n] (uint64 x, uint32 dx, uint32 dy) {
		return uint128(x) * x * dy >= uint128(n) * dx;
	};
	const uint64 sn = sqrtl(n);
	const uint64 cn = pow(n, 0.34); //cbrtl(n);
	uint64 x = n / sn;
	uint32 y = n / x + 1;
	uint128 ret = 0;
	stack<pair<uint32, uint32>> st;
	st.emplace(1, 0);
	st.emplace(1, 1);
	while (true) {
		uint32 lx, ly;
		tie(lx, ly) = st.top();
		st.pop();
		while (out(x + lx, y - ly)) {
		ret += x * ly + uint64(ly + 1) * (lx - 1) / 2;
		x += lx, y -= ly;
		}
		if (y <= cn) break;
		uint32 rx = lx, ry = ly;
		while (true) {
		tie(lx, ly) = st.top();
		if (out(x + lx, y - ly)) break;
		rx = lx, ry = ly;
		st.pop();
		}
		while (true) {
		uint32 mx = lx + rx, my = ly + ry;
		if (out(x + mx, y - my)) {
			st.emplace(lx = mx, ly = my);
		} 
		else {
			if (cut(x + mx, lx, ly)) break;
			rx = mx, ry = my;
		}
		}
	}
	for (--y; y > 0; --y) ret += n / y;
	return ret * 2 - sn * sn;
}


auto ans = sum_sigma0(n);
string s = "";
while (ans > 0) {
	s += char('0' + ans % 10);
	ans /= 10;
}
reverse(s.begin(), s.end());
cout << s << '\n';