#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

struct TwoSat {
	int N;
	typedef vector<int> vi;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f^1].push_back(j);
		gr[j^1].push_back(f);
	}
	void set_value(int x) { either(x, x); }

	void at_most_one(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = add_var();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = !(x&1);
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void die() {
  cout << "-1\n";
  exit(0);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> g(n);
  for(int i = 0; i < n; i++) cin >> g[i];
  string ret = "";
  for(int a = 0; a < k; a++) {
    TwoSat twosat(k);
    for(int i = 0; i < n; i++) {
      for(int a = 0; a < k; a++) {
        if(g[i][a] == 'X') continue;
        for(int b = a+1; b < k; b++) {
          if(g[i][b] == 'X') continue;
          int lhs = g[i][a] == 'T' ? -1-a : a;
          int rhs = g[i][b] == 'T' ? -1-b : b;
          twosat.either(lhs, rhs);
        }
      }
    }
    for(int b = 0; b < a; b++) {
      if(ret[b] == 'T') twosat.either(b, b);
      else twosat.either(-b-1, -b-1);
    }
    twosat.either(-a-1, -a-1);
    if(twosat.solve()) ret += "F";
    else ret += "T";
  }
  for(int i = 0; i < n; i++) {
    int match = 0;
    for(int j = 0; j < k; j++) match += g[i][j] == ret[j];
    if(match > 1) die();
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}