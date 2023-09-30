#include <bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked
#define putchar putchar_unlocked

using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f80 = long double;
using i128 = int128_t;
using u128 = uint128_t;

int get_int() {
    int c, n;
    while ((c = getchar()) < '0');
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + (c - '0');
    return n;
}


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
        for (int i = 0; i < 6; ++i) inv *= 2 - n * inv;
        r2 = -n % n;  // 2^128
        for (int i = 0; i < 4; ++i)
            if ((r2 <<= 1) >= mod)
                r2 -= mod;                             // 2^132
        for (int i = 0; i < 5; ++i) r2 = mul(r2, r2);  // 2^256
        assert(reduce(init(1)) == 1);
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
            std::swap(a, b);
        a -= b;
    }
    return b << shift;
}

u128 brent(u128 n, u128 c) {
    assert(n >= 4);
    if (!(n & 1))
        return 2;
    const u64 skip = 512;
    Mont mont(n);
    const u128 one = mont.init(1), mc = mont.init(c);
    auto add = [&](u128 x, u128 y) { return (x += y) >= n ? x - n : x; };
    auto sub = [&](u128 x, u128 y) { return i128(x -= y) < 0 ? x + n : x; };
    auto mul = [&](u128 x, u128 y) { return mont.mul(x, y); };
    auto f = [&](u128 x) { return add(mul(x, x), mc); };
    u128 y = one;
    for (u64 l = 1;; l <<= 1) {
        u128 x = y;
        for (u64 i = 0; i < l; ++i) y = f(y);
        u128 p = one;
        for (u64 k = 0; k < l; k += skip) {
            u128 sy = y;
            for (u64 i = 0; i < min(skip, l - k); ++i) y = f(y), p = mul(p, sub(y, x));
            u128 g = gcd(n, p);
            if (g == 1)
                continue;
            if (g == n)
                for (g = 1, y = sy; g == 1;) y = f(y), g = gcd(n, sub(y, x));
            return g;
        }
    }
    assert(0);
}

i128 get_i128() {
    int c;
    i128 n;
    while ((c = getchar()) < '0')
        if (c == EOF)
            return -1;
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + (c - '0');
    return n;
}

void print_u128(u128 n) {
    const u64 ten18 = u64(1e18);
    if (n >= ten18)
        printf("%llu%018llu", u64(n / ten18), u64(n % ten18));
    else
        printf("%llu", u64(n));
}

void solve() {
    i128 n;
    while ((n = get_i128()) >= 0) {
        i128 p1, p2;
        for (u64 c = 1;; ++c)
            if ((p1 = brent(n, c)) != n)
                break;
        p2 = n / p1;
        if (p1 > p2)
            swap(p1, p2);
        assert(p1 > 1 && p1 * p2 == n);
        print_u128(p1);
        printf(" ");
        print_u128(p2);
        puts("");
    }
}

int main() {
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
}