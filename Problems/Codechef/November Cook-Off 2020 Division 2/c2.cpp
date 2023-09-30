#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 100000000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a;
	while (b > 0) {
		if (b & 1) {res = (res * a); b--;}
		a = (a * a);
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

ll k, q;
ll mi = 1e17;
ll num;
//ll sum;

void solve(ll i, vector <ll>& fact, vl v, ll sum) {
	for (ll j = 0; j < k; j++) {
		sum -= v[j];
		v[j] *= fact[i];
		sum += v[j];
		if (i == num - 1) {
			mi = min(mi, sum);
			/*ll cs = 0;
			for (ll kk = 0; kk < k; kk++)
				cs += v[kk];
			assert(cs == sum);*/
			//continue;
		}
		else
			solve(i + 1, fact, v, sum);
		sum -= v[j];
		v[j] /= fact[i];
		sum += v[j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		//ll k, q;
		cin >> k >> q;
		vl v(k, 1);
		vector <ll> fact;
		while (q > 1) {
			ll spf = 1;
			for (ll i = 2; i * i <= q; i++) {
				if (q % i == 0) {
					spf = i;
					break;
				}
			}
			if (spf == 1) {
				fact.pb(q);
				break;
			}
			ll c = 0;
			while (q % spf == 0) {
				q = q / spf;
				c++;
			}
			fact.pb(power(spf, c));
		}
		num = fact.size();
		//assert(num < 8);
		//sum = k;
		if (k < num) {
			//cout << num << "\n";
			solve(0, fact, v, k);
            // cout<<k<<" "<<q<<endl;
			cout << mi << "\n";
		}
		else {
			ll d = 1;
			ll c = 0;
			for (auto i : fact) {
				//cout << i << "\n";
				//d = d * i;
				//cout << i << "\n";
				v[c] *= i;
				c++;
				if (c == k)
					c = 0;
			}
			ll ans = 0;
			for (auto i : v)
				ans += i;
            // cout<<k<<" "<<q<<endl;
			cout << ans << "\n";
			//assert(d == q);
		}
		mi = 1e17;
	}
}
