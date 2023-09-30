#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

template<int MOD>
struct ModInt {
    unsigned x;
    ModInt() : x(0) { }
    ModInt(signed sig) : x(sig) {  }
    ModInt(signed long long sig) : x(sig%MOD) { }
    int get() const { return (int)x; }
    ModInt pow(int p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }

    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }

    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    bool operator<(ModInt that) const { return x < that.x; }
    friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};

typedef ModInt<998244353> mint;

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string a,b;
        cin>>a>>b;

        int x = 0;
        for(int i = 0;i<n;i++){
            x+=a[i]!=b[i];
        }

        vector<mint> f(n+1);
        f[n] = mint(1);

        for(int i = n-1;i>=0;i--)
            f[i] = ((f[i+1]*mint(n-i))+mint(n))/mint(i);
        
        mint ans(0);
        for(int i = 0;i<=x;i++)
            ans+=f[i];
            
        cout<<ans<<endl;
    }
    return 0;
}