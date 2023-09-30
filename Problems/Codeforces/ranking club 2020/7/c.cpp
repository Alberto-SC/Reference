#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int gen_base(const int before, const int after) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    int base = uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
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
int n;
struct Hash {
    static const int mod = (int)1e9+123; 
    static int base;                     
    vector<int> pref1;
    Hash(const vector<int> & s): pref1(s.size()+1, 0){
        assert(base < mod);
        pref1[1]= powmod(base,s[0],mod);
        for (int i = 2;i<=n; ++i) { 
            pref1[i] = (pref1[i-1]%mod + powmod(base,s[i-1],mod)) % mod;
        }
    }
    inline int operator()(const int pos, const int len) const {
        int hash1 = ((((pref1[pos+len]%mod) - (pref1[pos-1]%mod))%mod)+mod)%mod;
        return hash1;
    }
};
 
int Hash::base((int)1e9+7);    
int main(){
    int m,l,l1,sz;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    Hash::base = gen_base(256, Hash::mod);
    Hash hash_a(a), hash_b(b);
    for (int i = 0;i<m;i++){
        cin>>l>>l1>>sz;
        if (hash_a(l, sz-1) == hash_b(l1,sz-1)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
 
    return 0;
}