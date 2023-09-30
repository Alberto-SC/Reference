#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

typedef unsigned long long ull;
typedef long long int lli;

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

int main(){__
    int n,q,l;
    string s,t;
    PolyHash::base = gen_base(256,2147483647);
    while(cin>>n>>q>>l){
        vector<PolyHash> hashes;
        for(int i = 0;i<n;i++){
            cin>>s;
            hashes.push_back(PolyHash(s));
        }
        lli ans = 0;
        for(int k = 0;k<q;k++){
            cin>>t;
            hashes.push_back(PolyHash(t));
            for(int j = 0;j<l;j++){
                for(int i = 0;i<n;i++){
                    if(j == 0){
                        if(hashes[i](1,l-1,l) == hashes[n](1,l-1,l))ans++;
                    }
                    else if(j ==l-1){
                        if(hashes[i](0,l-1,l) == hashes[n](0,l-1,l))ans++;
                    }
                    else {
                        if(hashes[i](j+1,l-j-1,l) == hashes[n](j+1,l-j-1,l)
                        && hashes[i](0,j,l) == hashes[n](0,j,l))ans++;
                    }
                }   
            }
            hashes.pop_back();
        }
        cout<<ans<<endl;
        // cout<<"HI"<<endl;
        // vector<int> 
    }
    return 0;
}