#include <bits/stdtr1c++.h>

// O(n^2/3)
struct _count_primes_struct_t_ {
    vector<int> primes;
    vector<int> mnprimes;
    int ans;
    int y;
    vector<pair<pair<int, int>, char>> queries;
 
    int count_primes(int n) {
        // this y is actually n/y
        // also no logarithms, welcome to reality, this y is the best for n=10^12 or n=10^13
        y = pow(n, 0.64);
        if (n < 100) y = n;
 
        // linear sieve
        primes.clear();
        mnprimes.assign(y + 1, -1);
        ans = 0;
        for (int i = 2; i <= y; ++i) {
            if (mnprimes[i] == -1) {
                mnprimes[i] = primes.size();
                primes.push_back(i);
            }
            for (int k = 0; k < primes.size(); ++k) {
                int j = primes[k];
                if (i * j > y) break;
                mnprimes[i * j] = k;
                if (i % j == 0) break;
            }
        }
        if (n < 100) return primes.size();
        int s = n / y;
 
        for (int p : primes) {
            if (p > s) break;
            ans++;
        }
        // pi(n / y)
        int ssz = ans;
 
        // F with two pointers
        int ptr = primes.size() - 1;
        for (int i = ssz; i < primes.size(); ++i) {
            while (ptr >= i && (int)primes[i] * primes[ptr] > n)
                --ptr;
            if (ptr < i) break;
            ans -= ptr - i + 1;
        }
 
        // phi, store all queries 
        phi(n, ssz - 1);
 
        sort(queries.begin(), queries.end());
        int ind = 2;
        int sz = primes.size();
 
        // the order in fenwick will be reversed, because prefix sum in a fenwick is just one query
        fenwick fw(sz);
        for (auto [na, sign] : queries) {
            auto [n, a] = na;
            while (ind <= n)
                fw.add(sz - 1 - mnprimes[ind++], 1);
            ans += (fw.ask(sz - a - 2) + 1) * sign;
        }
        queries.clear();
        return ans - 1;
    }
 
    void phi(int n, int a, int sign = 1) {
        if (n == 0) return;
        if (a == -1) {
            ans += n * sign;
            return;
        }
        if (n <= y) {
            queries.emplace_back(make_pair(n, a), sign);
            return;
        }
        phi(n, a - 1, sign);
        phi(n / primes[a], a - 1, -sign);
    }
 
    struct fenwick {
        vector<int> tree;
        int n;
 
        fenwick(int n = 0) : n(n) {
            tree.assign(n, 0);
        }
 
        void add(int i, int k) {
            for (; i < n; i = (i | (i + 1)))
                tree[i] += k;
        }
 
        int ask(int r) {
            int res = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1)
                res += tree[r];
            return res;
        }
    };
} _count_primes_struct_;
 
 
// O(n^3/4)
int count_primes(int n) {
    auto f = [&](int n) {
        return n;
    };
    auto pref = [&](int n) {
        return (n*(n+1))/2;
    };
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
    for(auto c:v)cout<<c<<" ";
    cout<<endl;
    vector<int> s(v.size());
    for (int i = 0; i < s.size(); ++i)
        s[i] =  pref(v[i]) - 1;
    for(auto c:s)cout<<c<<" ";
    cout<<endl;
    auto geti = [&](int x) {
        if (x <= sq) return (int)x - 1;
        else         return (int)(v.size() - (n / x));
    };
    cout<<s[geti(37)]<<endl;
    for (int p = 2; p * p <= n; ++p) {
        cout<<p<<endl;
        if (s[p - 1] != s[p - 2]) {
            int sp = s[p - 2];
            int p2 = p * p;
            cout<<sp<<" "<<p2<<endl;
            for (int i = (int)v.size() - 1; i >= 0; --i) {
                if (v[i] < p2) {
                    break;
                }
                s[i] -= (s[geti(v[i] / p)] - sp) * f(p);
                cout<<"I: "<<i<<" "<<v[i]/p<<" "<<geti(v[i]/p)<<" "<<f(p)<<endl;
            }
        }
    }
    for(auto c:s)cout<<c<<" ";
    cout<<endl;
    return s.back();
}


int count_primes2(int n) {
    vector<int> v;
    for (int k = 1; k * k <= n; ++k) {
        v.push_back(n / k);
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // for(auto c:v)cout<<c<<" ";
    // cout<<endl;
    int sq = sqrt(n);
    auto geti = [&](int x) {
        if (x <= sq) return (int)x - 1;
        else         return (int)(v.size() - (n / x));
    };

 
    vector<int> dp(v.size());
    for (int i = 0; i < v.size(); ++i)
        dp[i] = v[i];
 
    int a = 0;
    for (int p = 2; p * p <= n; ++p) {
        if (dp[geti(p)] != dp[geti(p - 1)]) {
            ++a;
            for (int i = (int)v.size() - 1; i >= 0; --i) {
                if (v[i] < p * p) break;
                dp[i] -= dp[geti(v[i] / p)] - a;
            }
        }
    }
    return dp[geti(n)] - 1;
}

#define MAXN 100
#define MAXM 100010
#define MAXP 10000010

using namespace std;

int prime_cnt[MAXP];
long long dp[MAXN][MAXM];

vector<int> primes;
bitset<MAXP> is_prime;

// void sieve(){
//     is_prime[2] = true;
//     for (int i = 3; i < MAXP; i += 2) is_prime[i] = true;

//     for (int i = 3; i * i < MAXP; i += 2){
//         for (int j = i * i; is_prime[i] && j < MAXP; j += (i << 1)){
//             is_prime[j] = false;
//         }
//     }

//     for (int i = 1; i < MAXP; i++){
//         prime_cnt[i] = prime_cnt[i - 1] + is_prime[i];
//         if (is_prime[i]) primes.push_back(i);
//     }
// }

void sieve(){
    vector<int> lp(MAXP+1);

    for(int i= 2;i<=MAXP;i++){
        if(lp[i]==0)lp[i] = i,primes.push_back(i);
        for(int j = 0;j<primes.size() && primes[j]<=lp[i] && primes[j]*i<=MAXP;j++)
            lp[primes[j]*i] = primes[j];
    }
    for (int i = 1; i < MAXP; i++)
        prime_cnt[i] = prime_cnt[i - 1] + (lp[i]==i);
}


void gen(){
    sieve();

    for (int m = 0; m < MAXM; m++) dp[0][m] = m;
    for (int n = 1; n < MAXN; n++){
        for (int m = 0; m < MAXM; m++){
            dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
        }
    }
}

long long phi(long long m, int n){
    if (n == 0) return m;
    if (m < MAXM && n < MAXN) return dp[n][m];
    if ((long long)primes[n - 1] * primes[n - 1] >= m && m < MAXP) return prime_cnt[m] - n + 1;

    return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
}

long long lehmer(long long m){
    if (m < MAXP) return prime_cnt[m];

    int s = sqrt(0.5 + m), y = cbrt(0.5 + m);
    int a = prime_cnt[y];

    long long res = phi(m, a) + a - 1;
    for (int i = a; primes[i] <= s; i++){
        res = res - lehmer(m / primes[i]) + lehmer(primes[i]) - 1;
    }
    return res;
}

int main(){
    auto start = clock();
    gen();
    printf("Time taken to generate = %0.6f\n\n", (clock() - start) / (double)CLOCKS_PER_SEC);

    cout << lehmer(1e12) << endl;
    printf("\nTime taken = %0.6f\n", (clock() - start) / (double)CLOCKS_PER_SEC);

    return 0;
}
