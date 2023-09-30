#include <bits/stdc++.h>
#define _C ios::sync_with_stdio(false);cin.tie(0);
#define xx first
#define yy second
#define ERR 0.00000001
#define INF (ll)1<<62
#define MOD 1000000007
#define pb push_back
#define forn(a,n) for(int i = (a) ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef complex<double> cp;
typedef vector<cp> polinomio;
typedef long double ld;
const ld PI = acos(-1);

struct nodo
{
	ll v;
	vll Fx;
	nodo():v(0){};
};

struct Grafo
{
	vector<nodo> v;
	vll vis;
	Grafo(ll n)
	{
		v.assign(n,nodo());
		v[0].v = 1;
		vis.assign(n,0);
		vis[0] = 1;
	}
	void join(ll x , ll y)
	{
		v[x].Fx.pb(y);
	}
	ll getAns(ll x)
	{
		if(vis[x])
			return v[x].v;
		vll::iterator it;
		for(it = v[x].Fx.begin() ; it != v[x].Fx.end(); it++)
			v[x].v = ((v[x].v + getAns(*it)) + MOD) % MOD;	
		vis[x] = 1;
		return v[x].v;
	}
};


int main()
{_C
	ll n, k , a , b;
	cin >> n >> k;
	Grafo g(n);
	forn(0,k)
	{
		cin >> a;
		while(a--)
		{
			cin >> b;
			g.join(b-1,i);
		}
	}
	ll ans = 0 , imp = 0, ac;
	forn(k,n)
	{
		ac = g.getAns(i);
		ans = ((ans + ac) + MOD) % MOD;
		if(ac > 0)
			++imp;
	}
	if(imp == 0)
		imp = 1;
	cout << ans%MOD << ' ' << imp%MOD << '\n';

	#ifdef LOCAL
	//	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}