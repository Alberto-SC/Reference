#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vi obtZF (string &s) {
    int n = s.size();
    vi zf = vi(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            zf[i] = min (r - i + 1, zf[i - l]);
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
            zf[i]++;
        if (i + zf[i] - 1 > r)
            l = i, r = i + zf[i] - 1;
    }
    
    return zf;
}

const int MX = 1005;
int n;
string s[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> s[i];
	
	int res = 0;
	forn (i, s[0].size()) {
		string t = s[0].substr(i);
		t.pb('#');
		
		for (int j = 1; j < n; j++)
			t += s[j] + "$";
			
		vi z = obtZF(t);
		
		int mx = s[0].size() - i, act = mx;
		for (int j = mx; j < t.size(); j++) {
			if (t[j] == '#' || t[j] == '$') {
				mx = min(mx, act);
				act = 0;
			} else {
				act = max(act, z[j]);
			}
		}
		
		res = max(res, mx);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
