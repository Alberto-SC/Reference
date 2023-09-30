#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
using namespace std;

long long gcd(long long a, long long b){ return b? gcd(b, a%b) : a; }
long long lcm(long long a, long long b){ return (!a or !b)? 0 : a * b / gcd(a,b); } 
long long  poww(long long  a, long long b){
	long long res = 1;
	while(b){ 
		if(b%2) res = res * a ; 
		a = a * a;  b>>=1;
	} return res;
}

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rnd(int n){return uniform_int_distribution<int>(0, n-1)(rng);}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template<class t,class u>bool mmax(t&a,u b){if(a<b)a=b;return a<b;}
template<class t,class u>bool mmin(t&a,u b){if(b<a)a=b;return b<a;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using li = long long;
using vi = vc<int>;
using ii = pair<int,int>;
// ---- しゃけ ツナマヨ ('-')7
using Matrix = vvc<li>;

const int mod = 1e9+7;

Matrix I(int n){
	vv(li,r,n,n,0);
	fore(i,0,n)r[i][i]=1;
	return r;
}
 
Matrix operator * (Matrix &a, Matrix &b){
	int n = sz(a), m=sz(b[0]), z=sz(a[0]);
	vv(li,r,n,m,0);
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]+=a[i][k]*b[k][j],r[i][j]%=(mod-1);
	return r;
}
 
Matrix be(Matrix b, li e){
	Matrix r = I(sz(b));
	while(e){
		if(e%2)r=r*b;
		b=b*b;
		e/=2;
	}
	return r;
}
 
li pow(li a, li e, li m){
	a%=mod;
	if(e==0)return 1;
	if(e%2) return  (a * pow(a,e-1,m))%m;
	return pow((a * a)%m, e/2, m);
}
 
 
li discrete(li a, li b, li m){
	a%=m; b%=m;
	if(b==1)return 0;
	int cnt = 0;
	li tmp = 1;
	for(li g=gcd(a,m);g!=1;g=gcd(a,m)){
		if(b%g)return -1;
		m/=g; b/=g;
		tmp = tmp * a / g%m;
		++cnt;
		if(b==tmp)return cnt;
	}
	map<li,li>baby;
	li s = ceil(sqrt(m));
	li base = b, key = tmp;
	fore(i,0,s){
		baby[base]=i;
		base = base * a %m;
	}
	base = pow(a,s,m);
	fore(i,1,s+2){
		key=base*key%m;
    	if(baby.count(key)) 
			return i * s-baby[key]+cnt;
	}
	return -1;
}

li powmod (li a, li b, li p) {
    li res = 1;
    while (b)
        if (b & 1)
            res = li (res * 1ll * a % p),  --b;
        else
            a = li (a * 1ll * a % p),  b >>= 1;
    return res;
}

li generator (li p) {
    vector<li> fact;
    li phi = p-1,  n = phi;
    for (li i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (li res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
 
li root(li k, li a, li m){
	li g = 5;
	li sq = ceil(sqrt(m));
    vector<ii> dec(sq);
    for (int i = 1; i <= sq; ++i)
        dec[i-1] = {pow(g, i * sq * k % (m - 1), m), i};
    sort(all(dec));
    int any_ans = -1;
    for (int i = 0; i < sq; ++i) {
        int my = pow(g, i * k % (m - 1), m) * a % m;
		ii x = {my, 0};
        auto it = lower_bound(all(dec), x);
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
            break;
        }
    }
		if (any_ans == -1) {
        return -1;
    }
		li delta = (m - 1) / gcd(k, m - 1);
		return pow(g, any_ans % delta, m);
}
 
int main(){_
	li k,a,m; cin>>k>>a;
	li res = root(k,a,mod);
	cout<<res<<ENDL;
}


