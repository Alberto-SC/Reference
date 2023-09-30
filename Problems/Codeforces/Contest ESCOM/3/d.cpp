#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<62;
#define N 1000100
int n; ll k;
ll XOR[N];
int pl[N], pr[N], pc[N];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n>>k;
	for (int i = 1; i < n; i ++) {
		int p; ll w;
		cin>>p>>w;
		p--;
		XOR[i] = XOR[p]^w;
	}
	sort(XOR, XOR+n);
	for (int i = 0; i < n; i ++) pr[i] = n;
	ll le = 0, ri = INF;
	ll S = 0;
	for (int p = 61; p >= 0; p--) {
		ll mi = le + (ri-le)/2;
		ll T = S;
		// cout << p << " " << S << endl;
		// cout << mi << endl;
		for (int i = 0; i < n; i ++) {
			pc[i] = lower_bound(XOR+pl[i], XOR+pr[i], mi^(XOR[i]>>p+1<<p+1)) - XOR;
			if ((XOR[i] >> p)&1) T += pr[i] - pc[i];
            else T += pc[i] - pl[i];
		}
        // cout<<"T: "<<T<<endl;
		if (T >= k) {
			ri = mi;
			for (int i = 0; i < n; i ++) {
				if ((XOR[i] >> p)&1) {
					pl[i] = pc[i];
				} else {
					pr[i] = pc[i];
				}
			}
		} else {
			le = mi;
			S = T;
			for (int i = 0; i < n; i ++) {
				if ((XOR[i] >> p)&1) {
					pr[i] = pc[i];
				} else {
					pl[i] = pc[i];
				}
			}
		}
	}
	cout << le << endl;
	return 0;
}