
 #include <bits/stdc++.h>
using namespace std;
using Integer128 = __int128;
typedef __int128 Intsote;
typedef long long int lli;
/*
    Function to print __int128 
*/
ostream& operator<<( ostream& dest, __int128_t value ){
    ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( ios_base::badbit );
        }
    }
    return dest;
}
//__________Exponenciacion y multiplicacion modular_________//
/*
	[Tested Timus 1141,1204, uva 1230,374,11029]
*/
//Ed1.- Do Not use mod_mult if it gives TLE
//Ed2.- Usually in small base and exponent 
//Ed3.- Al chile ya no lo uses 
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

int trail(lli a,lli b,int n){
    lli ntrail = mod_pow(10,n,10000000000);
    return mod_pow(a,b,ntrail);
} 
int leading(lli a,lli b,lli n){
    n--;
    lli nleading = mod_pow(10,n,10000000000);
    return (int)(pow(10, fmod(b*log10(a), 1))*nleading);
}
//_________Euclides extendido___________//
/*
    Solve ax+by = (a,b)
	// Algoritmo de Euclides extendido entre a y b. Ademas de devolver el gcd(a, b), resuelve la ecuación diofantica con el par (x, y).
	//Si el parametro mod no es especificado, se resuelve con aritmetica normal; si mod se especifica, la identidad se resuelve modulo mod.
	[Tested Timus 1141,1204]
*/
int gcd(int a,int b,int &x,int &y){
	if(b==0) {x = 1; y = 0; return a;}
	int r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
//________Inverso modular_________//
int inverse(int a, int m){
	int x, y ;
    if isPrime(m)return mod_pow(a,m-2,m);
	if(gcd( a, m, x, y ) != 1) return 0;
	return (x%m + m) % m;
}
/*
    All inverse (1 to p-1)%p
*/
vector<lli> allinverse(lli p){
    vector<lli> ans(p);
    ans[1] = 1;
    for(lli i = 2;i<p:i++){
        ans[i] = p-(p/i)*ans[p%i]%p;
    }
    return ans;
}
//__________Linear Diophantine Equation__________//
/*
    Use gcd -Extended euclides-
    Solve ax+by=c
    -Find any solution
    -Getting all solutions
    -Finding the number of solutions and the solutions in a given interval
    -Find the solution with minimum value of x+y
    [Tested Spoj - Crucial Equation,SGU 106,Codeforces - Ebony and Ivory,Codechef 
    - Get AC in one go, LightOj - Solutions to an equation]
*/
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) 
        return false;

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
//___________PHI de euler_____________//
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
//_________GCD and LCM__________//
/*
    [Tested ??]
*/
lli gcd(vector<lli> &nums){
    lli ans =0;
    for(lli &num:nums)ans =__gcd(ans,num);
    return ans;
}
lli lcm(lli a,lli b){
    return b*(a/__gcd(a,b));
}
lli lcm(vector<lli> & nums){
    lli ans = 1; 
    for(lli & num : nums) ans = lcm(ans, num);
    return ans;
}

//_________Teorema chino del residuo____________//
/*
    [Tested ???]
    if p1,p2,p3 are coprime 
*/
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
/*
    general CRT if pi,p2,p3 no coprimes
    return 0 if no solution
*/
inline lli normalize(lli x, lli mod) { x %= mod; if (x < 0) x += mod; return x; }
vector<int> a; 
vector<int> n;
lli LCM;
lli CRT(lli &ans){
    int t =a.size();
    ans = a[0];
    LCM = n[0];
    for(int i = 1; i < t; i++){
        int x1,d= gcd(LCM, n[i],x1,d);
        if((a[i] - ans) % d != 0) return 0;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * LCM, LCM * n[i] / d);
        LCM = lcm(LCM, n[i]); // you can save time by replacing above LCM * n[i] /d by LCM = LCM * n[i] / d
    }
    return 1;
}
//__________Factorial modulo p___________//
/*
    O(P logp n)
*/
int factmod(int n, int p) {
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
//________Discrete Log________//
int dlog(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * a) % m;
    map<int, int> vals;
    for (int p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * an) % m;
    }

    for (int q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

int powmod(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return res;
}

int dislog(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    map<int, int> vals;
    for (int p = n; p >= 1; --p)
        vals[powmod(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (powmod(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}

//_________Discrete root__________//
int generator(int p) {
    vector<int> fact;
    int phi = p-1, n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);

    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (int factor : fact) {
            if (mod_pow(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}
void discrete_root(int n, int k ,int a){
    int g = generator(n);
    // Baby-step giant-step discrete logarithm algorithm
    int sq = (int) sqrt (n + .0) + 1;
    vector<pair<int, int>> dec(sq);
    for (int i = 1; i <= sq; ++i)
        dec[i-1] = {mod_pow(g, i * sq * k % (n - 1), n), i};
    sort(dec.begin(), dec.end());
    int any_ans = -1;
    for (int i = 0; i < sq; ++i) {
        int my = mod_pow(g, i * k % (n - 1), n) * a % n;
        auto it = lower_bound(dec.begin(), dec.end(), make_pair(my, 0));
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) {
        puts("0");
        return 0;
    }
    // Print all possible answers
    int delta = (n-1) / gcd(k, n-1);
    vector<int> ans;
    for (int cur = any_ans % delta; cur < n-1; cur += delta)
        ans.push_back(mod_pow(g, cur, n));
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int answer : ans)
        printf("%d ", answer);
}
//__________________________Moudulo operator_________________________//
//(A + B) mod C = (A mod C + B mod C) mod C
//(A * B) mod C = (A mod C * B mod C) mod C
// xy (mod a) ≡ ((x (mod a) * y) (mod a))
// A^B mod M = ( A^(M-1) * A^(M-1) *.......* A^(M-1) * A^(x) ) mod M
// a^(p-1) mod p = 1, When p is prime.
//Mod for negatives,also work in positives ,(a%mod+mod)%mod;

//_________________Trailing zeors in factorial in any base_______________//
/*
    [Tested Codeforces round 538-C]
*/
lli trail_fact(lli n,lli b){
    lli ans = 1000000000000000000LL;
	for (lli i=2; i<=b; i++) {
		if (1LL * i * i > b) i = b;
		int cnt = 0;
		while (b % i == 0) {b /= i; cnt++;}
		if (cnt == 0) continue;
		lli tmp = 0, mul = 1;
		while (mul <= n / i) {mul *= i; tmp += n / mul;}
		ans = min(ans, tmp / cnt);
	}
    return ans;
}


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b); 
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return -1;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return -1;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return -1;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
    if (lx > rx)
        return -1;  
    return lx;
}

// This returns the pair {{min x, max x}, offset} or {{-1,-1},-1} if is not solution

pair<pair<int,int>,int> find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return {{-1,-1},-1};
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return {{-1,-1},-1};
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return {{-1,-1},-1};
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return {{-1,-1},-1};
    return {{lx,rx},b};
}

int gauss(int n){
    return (n*(n+1))/2;
}

// sum of floor((p*i)/q), 1<=i<=n
 
int f(int p, int q, int n) {
    int ans = gauss(n) * (p/q);
    cout<<p<<" "<<q<<" "<<n<<" "<<ans<<endl;
    p %= q;
    if (p != 0) {
        int N = (p*n)/q;
        cout<<N<<endl;
        ans += n * N - f(q, p, N) + N/p;
    }
    return ans;
}
// sum of floor((a*i+b)/c), 1<=i<=n

lli f(lli a, lli b, lli c, lli n){
	lli m = (a*n + b)/c;
	if(n==0 || m==0) return b/c;
	if(n==1) return b/c + (a+b)/c;
	if(a<c && b<c) return m*n - f(c, c-b-1, a, m-1);
	else return (a/c)*n*(n+1)/2 + (b/c)*(n+1) + f(a%c, b%c, c, n);
}




