#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Generate random base in (before, after) open interval:
int gen_base(const int before, const int after) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    seed ^= ull(new ull);
    mt19937 mt_rand(seed);
    int base = uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

struct PolyHash {
    // -------- Static variables --------
    static vector<int> pow1;        // powers of base modulo mod
    static vector<ull> pow2;        // powers of base modulo 2^64
    static int base;                     // base (point of hashing)
    
    // --------- Static functons --------
    static inline int diff(int a, int b) { 
    	// Diff between `a` and `b` modulo mod (0 <= a < mod, 0 <= b < mod)
        return (a -= b) < 0 ? a + 2147483647 : a;
    }
    
    static inline int mod(ull x) {
        x += 2147483647;
        x = (x >> 31) + (x & 2147483647);
        return int((x >> 31) + (x & 2147483647));
    }
    
    // -------------- Variables of class -------------
    vector<int> pref1; // Hash on prefix modulo mod
    vector<ull> pref2; // Hash on prefix modulo 2^64
    
    // Get power of base by modulo mod:
    inline int get_pow1(int p) const {
        static int __base[4] = {1, base, mod(ull(base) * base), mod(mod(ull(base) * base) * ull(base))};
        return mod(ull(__base[p % 4]) * pow1[p / 4]);
    }
    
    // Get power of base by modulo 2^64:
    inline ull get_pow2(int p) const {
        static ull __base[4] = {ull(1), ull(base), ull(base) * base, ull(base) * base * base};
        return pow2[p / 4] * __base[p % 4];
    }
    
    // Cunstructor from string:
    PolyHash(const string& s)
        : pref1(s.size()+1u, 0)
        , pref2(s.size()+1u, 0)
    {
        const int n = s.size(); 
        pow1.reserve((n+3)/4);
        pow2.reserve((n+3)/4);
        // Firstly calculated needed power of base:
        int pow1_4 = mod(ull(base) * base); // base^2 mod 2^31-1
        pow1_4 = mod(ull(pow1_4) * pow1_4); // base^4 mod 2^31-1
        ull pow2_4 = ull(base) * base;      // base^2 mod 2^64
        pow2_4 *= pow2_4;                   // base^4 mod 2^64
        while (4 * (int)pow1.size() <= n) {
            pow1.push_back(mod((ull)pow1.back() * pow1_4));
            pow2.push_back(pow2.back() * pow2_4);
        }
        int curr_pow1 = 1;
        ull curr_pow2 = 1;
        for (int i = 0; i < n; ++i) { // Fill arrays with polynomial hashes on prefix
            assert(base > s[i]);
            pref1[i+1] = mod(pref1[i] + (ull)s[i] * curr_pow1);
            pref2[i+1] = pref2[i] + s[i] * curr_pow2;
            curr_pow1 = mod((ull)curr_pow1 * base);
            curr_pow2 *= base;
        }
    }
    
    // Polynomial hash of subsequence [pos, pos+len)
    // If mxPow != 0, value automatically multiply on base in needed power. Finally base ^ mxPow
    inline pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += 2147483647;
        if (mxPow != 0) {
            hash1 = mod((ull)hash1 * get_pow1(mxPow-(pos+len-1)));
            hash2 *= get_pow2(mxPow-(pos+len-1));
        }
        return make_pair(hash1, hash2);
    }
};

// Init static variables of PolyHash class:
int PolyHash::base((int)1e9+7);    
vector<int> PolyHash::pow1{1};
vector<ull> PolyHash::pow2{1};

int main() {
    string a;
    {
        vector<char> buf(1+1000000);
        scanf("%1000000s", &buf[0]);
        a = string(&buf[0]);
    }
    
    // Gen random base of hashing:
    PolyHash::base = gen_base(256, 2147483647);
    
    // Cunstruct polynomial hashes on prefix of original and reversed string:
    PolyHash hash_a(a); 
    reverse(a.begin(), a.end());
    PolyHash hash_b(a);
    
    // Get length of strings (mxPow == n)
    const int n = (int)a.size();
    
    ull answ = 0;
    for (int i = 0, j = n-1; i < n; ++i, --j) {
        // Palindromes odd length:
        int low = 0, high = min(n-i, n-j)+1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (hash_a(i, mid, n) == hash_b(j, mid, n)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        answ += low;
        // Palindromes even length:
        low = 0, high = min(n-i-1, n-j)+1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (hash_a(i+1, mid, n) == hash_b(j, mid, n)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        answ += low;
    }
    cout << answ;
    return 0;
}


// int PolyHash::base((int)1e9+7);    
// vector<int> PolyHash::pow1{1};
// vector<ull> PolyHash::pow2{1};
// int main(){
//     string a,b;
//     cin>>a;
//     b = a;
//     reverse(a.begin(),a.end());
//     const int mxPow = std::max((int)a.size(), (int)b.size());
//     PolyHash::base = gen_base(256, PolyHash::mod);
//     PolyHash hash_a(a), hash_b(b);    n 
//     for (int i = 0; i<a.size();i++){
//         auto need = hash_a(0,i+1,mxPow);
//         int size = a.size();
//         if
//         if (hash_a(i, b.size(), mxPow) == need) {
//             printf("%d ", i);
//         }
//     }
 
//     return 0;
// }
