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
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define deb(x) cout << #x": " << (x) << endl;

lli gcd(lli a, lli b){return (b?gcd(b,a%b):a);}
lli lcm(lli a, lli b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
int popcount(lli x) { return __builtin_popcountll(x); }

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rnd(int n){return uniform_int_distribution<int>(0, n-1)(rng);}

lli poww(lli a, lli b){
	lli res =1;
	while(b){ if(b&1) res = res * a; a = a*a; b/=2; }
	return res;
}

vvc<int> graph(int n, int m, bool dir=1){
	vv(int,v,n+1,0);
	fore(i,0,m){
		int a,b; cin>>a>>b;
		v[a].pb(b);
		if(dir)v[b].pb(a);
	}
	return v;
}
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
// ---- コーディングはここから！ ('-')7

void solve(){
	string s; cin>>s;
	int n = sz(s);
	int res = 0;
	fore(i,0,n){
		if(s[i]=='0')continue;
		if(i<n-1 and s[i]==s[i+1])s[i+1]='0',res++;
		if(i<n-2 and s[i]==s[i+2])s[i+2]='0',res++;
	}
	cout<<res<<ENDL;
}

int main(){_
	int t; cin>>t; while(t--)
	solve();
}
