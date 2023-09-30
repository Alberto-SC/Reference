/*
    Dynamic hull for max dot queries

    Complexity:
        - Add: O(log n)
        - Query: O(log^2 n) but very fast in practice
    Author: 
        https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
    Tested: 
        - http://codeforces.com/gym/100377/problem/L
*/

const ll inf = 1e18;
bool Q = 0
struct Line {
	mutable ll m, b, x;
 
	bool operator < (const Line ot) const {
		return Q ? x < ot.x : m < ot.m;
	}
};
 
ll ceil (ll a, ll b) {
	if (a < 0 != b < 0) return a / b;
	return (abs(a) + abs(b) - 1) / abs(b);
}
 
ll intersection (const Line &p, const Line &q) {
	return ceil(q.b - p.b, p.m - q.m);
}
 
struct Hull : multiset<Line> {
	bool valid (auto it) {
		if (it == begin()) {
			auto sig = it;
			sig++;
			if (sig != end()) sig->x = intersection(*it, *sig);
			return it->x = -inf;
		}
 
		auto ant = it, sig = it;
		ant--, sig++;
 
		if (sig == end()) {
			it->x = intersection(*it, *ant);
			return 1;
		}
 
		ll x = intersection(*it, *ant);
		ll y = intersection(*it, *sig);
 
		if (x > y) return 0;
		it->x = x, sig->x = y;
		return 1;
	}
 
	void add (ll m, ll b) {
		auto it = lower_bound({m, b, -inf});
 
		if (it != end() && it->m == m) {
			if (it->b > b) return;
			it->b = b;
		} else {
			it = insert({m, b, -inf});
		}
 
		if (!valid(it)) {
			erase(it);
			return;
		}
 
		auto ant = it;
		while (ant != begin()) {
			if (valid(--ant)) break;
			erase(ant);
			if (it == begin()) { it->x = -inf; break; }
			ant = it;
		}
 
		auto sig = it;
		sig++;
		while (sig != end() && !valid(sig))
			erase(sig++);
	}
 
	ll query (ll x) {
		if (empty()) return 0;
 
		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return x * it->m + it->b;
	}
}h;



#define ll long long
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { 
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};