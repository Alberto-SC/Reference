#include <bits/stdc++.h>                                        // exclude-line
using namespace std;                                            // exclude-line
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);      // exclude-line
#define endl '\n'                                               // exclude-line

/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: Count the number of primes up to $n^{12}$ 
 * Time:  $O(n^{\frac{2}{3}})$ count of primes for $n^{12} \sim 5.15s$   for sum of primes $n^{11}  \sim 4.39s$ 
 * Status: Tested
 * Usage: 
 *       k = 0; gen(); lehmer(n) // k = 0 is count of primes
 *       for sum of primes -> k = 1; count_primes(n);
 */


// If sum of primes is needed use int128
#define int __int128                                          
#define MAXN 100
#define MAXM 100007
#define MAXP 10000007
int prime_cnt[MAXP];
int prime_sum[MAXP];
long long dp[MAXN][MAXM];

//Function to print __int128
std::ostream&
operator<<( std::ostream& dest, __int128_t value ){
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

vector<int> primes;
bitset<MAXP> is_prime;
 
// modify k to calc sum of primes p^k with p^k <= n
int k = 0;
int F(int n){
    return pow(n,k);
};

int pref(int n){
    if(k == 0)return n;
    if(k == 1)return (n*(n+1))/2;
    if(k == 2)return (n*(n+1)*(2*n+1))/6;
    return 1;
}


vector<int> lp(MAXP+1);
void gen(){
    lp.assign(MAXP,0);
    primes.clear();
    for(int i= 2;i<=MAXP;i++){
        if(lp[i]==0)lp[i] = i,primes.push_back(i);
        for(int j = 0;j<primes.size() && primes[j]<=lp[i] && primes[j]*i<=MAXP;j++)
            lp[primes[j]*i] = primes[j];
    }
    for (int i = 2; i < MAXP; i++){

        prime_cnt[i] = prime_cnt[i-1] + (lp[i]==i);
        prime_sum[i] = prime_sum[i-1] + (lp[i]==i?F(i):0);
    }

    for (int m = 0; m < MAXM; m++) dp[0][m] = pref(m);
    
    for (int n = 1; n < MAXN; n++){
        for (int m = 0; m < MAXM; m++){
            dp[n][m] = dp[n - 1][m] - (dp[n - 1][m/primes[n - 1]]*F(primes[n-1]));
        }
    }
}
 
int phi(int m, int n){
    if (n == 0) return pref(m);
    if (m < MAXM && n < MAXN) return dp[n][m];
    if (primes[n - 1] * primes[n - 1] >= m && m < MAXP) return prime_sum[m] - pref(n) + 1;
 
    return phi(m, n - 1) - (phi(m/primes[n - 1], n - 1)*F(primes[n-1]));
}


/*- for some reason this not work for sum of power primes or for k>=1 use count primes instead */
int lehmer(int m){
    if (m < MAXP) return prime_sum[m];
    int s = sqrt(0.5 + m), y = cbrt(0.5 + m);
    int a = prime_cnt[y];
    int res = phi(m, a);
    for (int i = a; primes[i] <= s; i++){
        int x = lehmer(m/primes[i]);
        int y = lehmer(primes[i-1]);
        res = res - ((lehmer(m / primes[i]) - lehmer(primes[i-1]))*F(primes[i])) - F(primes[i]);
    }
    a = prime_sum[s];
    return (res+a)-1;
}
 
/*+ Use this function if k>=1 */
int count_primes(int n) {
    vector<int> v;
    v.reserve((int)sqrt(n) * 2 + 20);
    int sq;{
        int k = 1;
        for (; k * k <= n; ++k) {
            v.push_back(k);
        }
        --k;
        sq = k;
        if (k * k == n) --k;
        for (; k >= 1; --k) {
            v.push_back(n / k);
        }
    }
    vector<int> s(v.size());
    for (int i = 0; i < s.size(); ++i)
        s[i] =  pref(v[i]) - 1;
    auto geti = [&](int x) {
        if (x <= sq) return (int)x - 1;
        else  return (int)(v.size() - (n / x));
    };
    for (int p = 2; p * p <= n; ++p) {
        if (s[p - 1] != s[p - 2]) {
            int sp = s[p - 2];
            int p2 = p * p;
            for (int i = (int)v.size() - 1; i >= 0; --i) {
                if (v[i] < p2) {
                    break;
                }
                s[i] -= (s[geti(v[i] / p)] - sp) * F(p);
            }
        }
    }
    return s.back();
}

// exclude-from-here

signed main(){__
    long long n,t;
    cin>>n;
    k = 0;
    gen();
    auto start = clock();
    cout<<lehmer(n)<<endl;
    printf("\nTime taken = %0.6f\n", (clock() - start) / (double)CLOCKS_PER_SEC);
    start = clock();
    cout<<count_primes(n)<<endl;
    printf("\nTime taken = %0.6f\n", (clock() - start) / (double)CLOCKS_PER_SEC);
    return 0;
}