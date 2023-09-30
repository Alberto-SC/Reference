/**
 * Author: Simon Lindholm
 * Date: 2019-05-22
 * License: CC0
 * Description: Chinese Remainder Theorem.
 * \text{crt(a, m, b, n)} computes $x$ such that $x\equiv a \pmod m$, $x\equiv b \pmod n$.
 * If $|a| < m$ and $|b| < n$, $x$ will obey $0 \le x < \text{lcm}(m, n)$.
 * Assumes $mn < 2^{62}$.
 * given a set of congruence equations -> 
 * $ a \equiv a_{1} (mod p_{1})$
 * $ a \equiv a_{2} (mod p_{2})$
 * $ \dots $
 * $ a \equiv a_{k} (mod p_{k})$
 * Return a if $p_{i}$ are pairwise coprimes
 * Time: $\log(n)$
 * Status: Works
 */

// #include "ModInverse.h"
// #include "euclid.h"

int crt(int a, int m, int b, int n) {
	if (n > m) swap(a, b), swap(m, n);
	int x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int lcm(int a,int b){
	return a*b/__gcd(a,b);
}

vector<int>nums;
vector<int>rem;
int CRT() { 
    int prod = 1; 
    for (int i = 0; i < nums.size(); i++) 
        prod *= nums[i];   
    int result = 0;   
    for (int i = 0; i < nums.size(); i++) { 
        int pp = prod / nums[i]; 
        result += rem[i] * inverse(pp, nums[i]) * pp; 
    } 
    return result % prod; 
} 
/*+ general CRT if pi,p2,p3 no coprimes, return 0 if no solution */
inline int normalize(int x, int mod) { x %= mod; if (x < 0) x += mod; return x; }
vector<int> a; 
vector<int> p;
int LCM;
int CRT(int &ans){
    int t =a.size();
    ans = a[0];
    LCM = p[0];
    for(int i = 1; i < t; i++){
        int x1,d= gcd(LCM, p[i],x1,d);
        if((a[i] - ans) % d != 0) return 0;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (p[i] / d) * LCM, LCM * p[i] / d);
        LCM = lcm(LCM, p[i]); // you can save time by replacing above LCM * n[i] /d by LCM = LCM * n[i] / d
    }
    return 1;
}