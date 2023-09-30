#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1001001;
const ll mod = 1000000007;

ll modpow(ll a, ll b){
    if(b == 0)return 1;
    ll h = modpow(a,b/2);
    if(b%2 == 0)return (h*h)%mod;
    return (a*((h*h)%mod))%mod;
}

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll bin(ll a, ll b){
    if(a < 0 || b < 0 || a < b)return 0;
    ll p = (FAC[a] * INV[b])%mod;
    return (p * INV[a-b])%mod;
}

ll patrick(ll a, ll b){
    return (bin(a+4,b+2) - 2*bin(a+2,b+1) - bin(a, b) + 3*mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        t *= ll(c1+1);
        t %= mod;
    }
    INV[MAXN-1] = modpow(FAC[MAXN-1], mod-2);
    for(int c1 = MAXN-2; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1] * ll(c1+1))%mod;
    }

    int q;
    cin >> q;
    rep(c1,0,q){
        ll a,b,x;
        cin >> a >> b >> x;
        a--;
        b--;
        if(patrick(a, b) == x){
            cout << "Correct\n";
        }
        else{
            cout << "Incorrect\n";
        }
    }
    return 0;
}

