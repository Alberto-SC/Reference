#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

typedef unsigned long long u64;
typedef __int128_t i128;
typedef __uint128_t u128;

struct u256 {
    u256() {}
    u256(u128 l, u128 h) : lo(l), hi(h) {}
    static u256 mul128(u128 a, u128 b) {
        u64 a_hi = a >> 64, a_lo = u64(a);
        u64 b_hi = b >> 64, b_lo = u64(b);
        u128 p01 = u128(a_lo) * b_lo;
        u128 p12 = u128(a_hi) * b_lo + u64(p01 >> 64);
        u64 t_hi = p12 >> 64, t_lo = p12;
        p12 = u128(a_lo) * b_hi + t_lo;
        u128 p23 = u128(a_hi) * b_hi + u64(p12 >> 64) + t_hi;
        return u256(u64(p01) | (p12 << 64), p23);
    }
    u128 lo, hi;
};

struct Mont {
    Mont(u128 n) : mod(n) {
        assert(n & 1);
        inv = n;
        rep(i, 0, 6) inv *= 2 - n * inv;
        r2 = -n % n;
        rep(i, 0, 4) if ((r2 <<= 1) >= mod) r2 -= mod;
        rep(i, 0, 5) r2 = mul(r2, r2);
    }
    u128 reduce(u256 x) const {
        u128 y = x.hi - u256::mul128(x.lo * inv, mod).hi;
        return i128(y) < 0 ? y + mod : y;
    }
    u128 reduce(u128 x) const { return reduce(u256(x, 0)); }
    u128 init(u128 n) const { return reduce(u256::mul128(n, r2)); }
    u128 mul(u128 a, u128 b) const { return reduce(u256::mul128(a, b)); }
    u128 mod, inv, r2;
};

u128 ctz(u128 x) {
    if (u64(x) == 0)
        return __builtin_ctzll(u64(x >> 64)) + 64;
    else
        return __builtin_ctzll(u64(x));
}

u128 gcd(u128 a, u128 b) {
    if (b == 0)
        return a;
    int shift = ctz(a | b);
    b >>= ctz(b);
    while (a) {
        a >>= ctz(a);
        if (a < b)
            swap(a, b);
        a -= b;
    }
    return b << shift;
}

inline i128 getint() {
    i128 ret = 0;
    bool ok = 0, neg = 0;
    for (;;) {
        int c = getchar();
        if (c >= '0' && c <= '9')
            ret = (ret << 3) + ret + ret + c - '0', ok = 1;
        else if (ok)
            return neg ? -ret : ret;
        else if (c == '-')
            neg = 1;
    }
}

void printint(u128 n) {
    const u64 ten18 = u64(1e18);
    if (n >= ten18)
        printf("%llu%018llu", u64(n / ten18), u64(n % ten18));
    else
        printf("%llu", u64(n));
}

u128 rho(u128 n) {
    if (!(n & 1))
        return 2;
    const u64 skip = (n < (1ull << 63)) ? 32 : 512;
    Mont mont(n);
    auto add = [&](u128 x, u128 y) { return (x += y) >= n ? x - n : x; };
    auto sub = [&](u128 x, u128 y) { return i128(x -= y) < 0 ? x + n : x; };
    auto mul = [&](u128 x, u128 y) { return mont.mul(x, y); };
    u64 c = rand();
    while (1) {
        ++c;
        const u128 one = mont.init(1), mc = mont.init(c);
        auto f = [&](u128 x) { return add(mul(x, x), mc); };
        u128 y = one;
        int cnt = 0;
        for (u64 l = 1;; l <<= 1) {
            u128 x = y;
            for (u64 i = 0; i < l; ++i) y = f(y), cnt++;
            u128 p = one;
            for (u64 k = 0; k < l; k += skip) {
                u128 sy = y;
                for (u64 i = 0; i < min(skip, l - k); i++) y = f(y), p = mul(p, sub(y, x)), cnt++;
                u128 g = gcd(n, p);
                if (g == 1)
                    continue;
                if (g == n) {
                    for (g = 1, y = sy; g == 1;) y = f(y), g = gcd(n, sub(y, x));
                }
                if (g != n) {
                    return g;
                }
                break;
            }
            //			fprintf(stderr,"%llu %d\n",l,cnt);
        }
    }
}

void solve() {
    i128 n = getint();
    i128 p = rho(n);
    i128 q = n / p;
    if (p > q)
        swap(p, q);
    printint(p);
    putchar(' ');
    printint(q);
    puts("");
}

int main() { solve(); }