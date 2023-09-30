#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL); 

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
    static vector<int> pow1;   
    static vector<ull> pow2;   
    static int base;           
    static inline int diff(int a, int b) { 
        return (a -= b) < 0 ? a + 2147483647 : a;
    }
    
    static inline int mod(ull x) {
        x += 2147483647;
        x = (x >> 31) + (x & 2147483647);
        return int((x >> 31) + (x & 2147483647));
    }
    
    vector<int> pref1; 
    vector<ull> pref2; 
    
    inline int get_pow1(int p) const {
        static int __base[4] = {1, base, mod(ull(base) * base), mod(mod(ull(base) * base) * ull(base))};
        return mod(ull(__base[p % 4]) * pow1[p / 4]);
    }
    
    inline ull get_pow2(int p) const {
        static ull __base[4] = {ull(1), ull(base), ull(base) * base, ull(base) * base * base};
        return pow2[p / 4] * __base[p % 4];
    }    
    PolyHash(const string& s)
        : pref1(s.size()+1u, 0)
        , pref2(s.size()+1u, 0)
    {
        const int n = s.size(); 
        pow1.reserve((n+3)/4);
        pow2.reserve((n+3)/4);
        int pow1_4 = mod(ull(base) * base); 
        pow1_4 = mod(ull(pow1_4) * pow1_4); 
        ull pow2_4 = ull(base) * base;      
        pow2_4 *= pow2_4;                   
        while (4 * (int)pow1.size() <= n) {
            pow1.push_back(mod((ull)pow1.back() * pow1_4));
            pow2.push_back(pow2.back() * pow2_4);
        }
        int curr_pow1 = 1;
        ull curr_pow2 = 1;
        for (int i = 0; i < n; ++i) { 
            assert(base > s[i]);
            pref1[i+1] = mod(pref1[i] + (ull)s[i] * curr_pow1);
            pref2[i+1] = pref2[i] + s[i] * curr_pow2;
            curr_pow1 = mod((ull)curr_pow1 * base);
            curr_pow2 *= base;
        }
    }
    
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
int PolyHash::base((int)1e9+7);    
vector<int> PolyHash::pow1{1};
vector<ull> PolyHash::pow2{1};

int main() {__
    int n;
    cin>>n;
    string s;
    cin>>s;
    PolyHash::base = gen_base(256, 2147483647);    
    PolyHash h1(s); 
    string s2 = s;
    reverse(s2.begin(), s2.end());
    PolyHash h2(s2);
    n*=2;
    bool flag = false;
    for(int i = 0;i<=n/2;i++){

        int l = (n/2)-i;
        auto a = h1(0,i,n);
        auto b = h2(l,i,n);

        auto c = h2(0,l,n);
        auto d = h1(i,l,n);

        if(a == b && c == d){
            string ans = s.substr(0,i)+s.substr(n-l,l);
            flag = true;
            cout<<ans<<endl<<i<<endl;
            break;
        }
    }
    if(!flag)cout<<-1<<endl;
    cout<<endl;
}