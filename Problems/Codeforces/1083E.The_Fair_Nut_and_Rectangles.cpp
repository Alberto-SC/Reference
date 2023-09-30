#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
struct rect{
    lli x,y,a;
    bool operator < (const rect B){
        if(x == B.x)return y<B.y;
        return x<B.x;
    }
};

const lli inf = 1e18;
bool Q = 0;
struct Line {
	mutable lli m, b, x;
	bool operator < (const Line ot) const {
		return Q ? x < ot.x : m < ot.m;
	}
};

 
lli ceil (lli a, lli b) {
	if (a < 0 != b < 0) return a / b;
	return (abs(a) + abs(b) - 1) / abs(b);
}
 
lli interseccion (const Line &p, const Line &q) {
	return ceil(q.b - p.b, p.m - q.m);
}

struct Hull : multiset<Line> { 
	void add (lli m, lli b) {
		auto it = end();
		if (size() && (--it)->m == m) {
			if (it->b >= b) return;
			it->b = b;
		} else {
			it = insert({m, b, -inf});
		}
		while (size() >= 3) {
			auto ant1 = it; ant1--;
			auto ant2 = ant1; ant2--;
			
			auto x = interseccion(*ant1, *ant2);
			auto y = interseccion(*ant1, *it);
			
			if (x < y) break;
			erase(ant1);
		}
		if (size() >= 2) {
			auto ant = it; ant--;
			it->x = interseccion(*ant, *it);
		}
	}
 
	lli query (lli x) {
		if (empty()) 
         0;
		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return x * it->m + it->b;
	}
};


int main(){__
    lli n,x,y,a;
    cin>>n;
    vector<rect> r;
    for(int i = 0;i<n;i++){
        cin>>x>>y>>a;
        r.push_back({x,y,a});
    }
    sort(r.begin(),r.end());
    vector<lli> DP(n);
    Hull CH;
    CH.add(0,0);
    for(int i = 0;i<n;i++){ 
        DP[i] = (r[i].x*r[i].y)-r[i].a + CH.query(-r[i].y);
        // cout<<DP[i]<<" "<<CH.query(-r[i].y)<<endl;
        CH.add(r[i].x,DP[i]);
    }
    lli ans = 0;
    for(int i = 0;i<n;i++){
        ans = max(DP[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}