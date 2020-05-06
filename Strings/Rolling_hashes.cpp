#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int gen_base(const int before, const int after) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    int base = uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

struct PolyHash {
    static const int mod = (int)1e9+123; // prime mod of polynomial hashing
    static vector<int> pow1;        // powers of base modulo mod
    static vector<ull> pow2;        // powers of base modulo 2^64
    static int base;                     // base (point of hashing)
    static inline int diff(int a, int b) { 
        return (a -= b) < 0 ? a + mod : a;
    }
    vector<int> pref1; // Hash on prefix modulo mod
    vector<ull> pref2; // Hash on prefix modulo 2^64

    // Cunstructor from string:
    PolyHash(const string& s): pref1(s.size()+1u, 0) , pref2(s.size()+1u, 0){
        assert(base < mod);
        const int n = s.size(); // Firstly calculated needed power of base:
        while ((int)pow1.size() <= n) {
            pow1.push_back(1LL * pow1.back() * base % mod);
            pow2.push_back(pow2.back() * base);
        }
        for (int i = 0; i < n; ++i) { // Fill arrays with polynomial hashes on prefix
            assert(base > s[i]);
            pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
            pref2[i+1] = pref2[i] + s[i] * pow2[i];
        }
    }
 
    // Polynomial hash of subsequence [pos, pos+len)
    // If mxPow != 0, value automatically multiply on base in needed power. Finally base ^ mxPow
    inline pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxPow != 0) {
            hash1 = 1LL * hash1 * pow1[mxPow-(pos+len-1)] % mod;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return make_pair(hash1, hash2);
    }
};
 
// Init static variables of PolyHash class:
int PolyHash::base((int)1e9+7);    
vector<int> PolyHash::pow1{1};
vector<ull> PolyHash::pow2{1};
int main() {
    char buf[1+100000];
    scanf("%100000s", buf);
    std::string a(buf);
    scanf("%100000s", buf);
    std::string b(buf);
    const int mxPow = std::max((int)a.size(), (int)b.size());
 
    // Gen random base of hashing:
    PolyHash::base = gen_base(256, PolyHash::mod);
 
    // Create hashing objects of strings `a` and `b`:
    PolyHash hash_a(a), hash_b(b);
 
    // Copy needed hash from all string b:
    const auto need = hash_b(0, (int)b.size(), mxPow);
 
    // Iterate over subsequences of string `a` neede length and compare hash with hash of string b:
    for (int i = 0; i + (int)b.size() <= (int)a.size(); ++i) {
        if (hash_a(i, b.size(), mxPow) == need) {
            printf("%d ", i);
        }
    }
 
    return 0;
}