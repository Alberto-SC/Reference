#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int gen_base(const int before, const int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    seed ^= ull(new ull);
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}
struct PolyHash {
    static std::vector<int> pow1;        // powers of base modulo mod
    static std::vector<ull> pow2;        // powers of base modulo 2^64
    static int base;                     // base (point of hashing)
    static inline int diff(int a, int b) { 
        return (a -= b) < 0 ? a + 2147483647 : a;
    }
    static inline int mod(ull x) {
        x += 2147483647;
        x = (x >> 31) + (x & 2147483647);
        return int((x >> 31) + (x & 2147483647));
    }
    std::vector<int> pref1; // Hash on prefix modulo mod
    std::vector<ull> pref2; // Hash on prefix modulo 2^64
    inline int get_pow1(int p) const {
        static int __base[4] = {1, base, mod(ull(base) * base), mod(mod(ull(base) * base) * ull(base))};
        return mod(ull(__base[p % 4]) * pow1[p / 4]);
    }
    
    inline ull get_pow2(int p) const {
        static ull __base[4] = {ull(1), ull(base), ull(base) * base, ull(base) * base * base};
        return pow2[p / 4] * __base[p % 4];
    }
    
    PolyHash(const std::string& s)
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
    inline std::pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += 2147483647;
        if (mxPow != 0) {
            hash1 = mod((ull)hash1 * get_pow1(mxPow-(pos+len-1)));
            hash2 *= get_pow2(mxPow-(pos+len-1));
        }
        return std::make_pair(hash1, hash2);
    }
};
int PolyHash::base((int)1e9+7);    
std::vector<int> PolyHash::pow1{1};
std::vector<ull> PolyHash::pow2{1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    PolyHash::base = gen_base(256, 2147483647);
    PolyHash hash_a(a); 
    reverse(a.begin(), a.end());
    PolyHash hash_b(a);
    const int n = (int)a.size();
    ull ans = 0;
    vector<int> f(n+1);
    f[0] = 1;
    for(int i = 1;i<n;i++){ 
        int mid =((i+1)/2)-1;
        if(hash_a(0,i+1,n) == hash_b(n-i-1,i+1,n))
            f[i] = f[((i+1)/2)-1]+1;
        ans+=f[i];
    }
    cout<<ans+1<<endl;
    return 0;
}