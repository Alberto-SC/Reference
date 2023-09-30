#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int lli;
const ld PI = acos(-1);
struct segment{
    ld x1,x2,y;
};

const ld inf = 1e9;
bool Q = 0;
struct Line {
	mutable lli m, b;
    mutable ld x;
	// Maximo: m < ot.m
	// Minimo: m > ot.m
	bool operator < (const Line ot) const {
		return Q ? isless(x,ot.x) : m < ot.m;
	}
};

pair<ld,ld> norm (ld x,ld y){
    lli a = x,b= y;
	lli g = __gcd(a,b);
	a /= g;
	b /= g;
    return {(ld)a,(ld)b};
}
ld intersection (const Line &p, const Line &q) {
	auto x = norm(q.b - p.b,p.m - q.m);
    return x.first/x.second;
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

		lli x = intersection(*it, *ant);
		lli y = intersection(*it, *sig);

		if (x > y) return 0;
		it->x = x, sig->x = y;
		return 1;
	}

	void add (lli m, lli b) {
		auto it = lower_bound({m, b, -inf});

		if (it != end() && it->m == m) {
			//Maximo: it->b > b
			//Minimo: it->b < b
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

	ld query (ld x) {
		if (empty()) return 0;

		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return (x * it->m*1.0l) + (ld)it->b;
	}
};
struct LineM {
	mutable lli m, b;
    mutable ld x;
	// Maximo: m < ot.m
	// Minimo: m > ot.m
	bool operator < (const LineM ot) const {
		return Q ? isless(x,ot.x) : m > ot.m;
	}
};

ld intersection (const LineM &p, const LineM &q) {
	auto x = norm(q.b - p.b,p.m - q.m);
    return x.first/x.second;
}

struct Hullm : multiset<LineM> {
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

		lli x = intersection(*it, *ant);
		lli y = intersection(*it, *sig);

		if (x > y) return 0;
		it->x = x, sig->x = y;
		return 1;
	}

	void add (lli m, lli b) {
		auto it = lower_bound({m, b, -inf});

		if (it != end() && it->m == m) {
			//Maximo: it->b > b
			//Minimo: it->b < b
			if (it->b < b) return;
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

	ld query (ld x) {
		if (empty()) return 0;

		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return (x * it->m*1.0l) + (ld)it->b;
	}
};

ld acot(ld x){
    return (PI/2.0)- atan (x);
}
ld cot(ld x){
    return cos(x)/sin(x);
}

ld pendiente(ld x1,ld y1,ld x2,ld y2){
    auto x = norm(x2-x1,y2-y1);
    ld pend  = x.first/x.second;
    return pend;
}


int main(){
    int n;
    ld x1,x2,y;
    cin>>n;
    vector<segment> s;
    ld mnx = 1e6+9;
    ld mxx = -mnx;
    for(int i = 0;i<n;i++){
        cin>>x1>>x2>>y;
        s.push_back({x1,x2,y});
        mxx = max(x2,mxx);
        mnx = min(mnx,x1);
    } 
    vector<pair<ld,ld>> pendientes;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(s[i].y<=s[j].y || i ==j)continue;
            pendientes.push_back({pendiente(s[i].x2,s[i].y,s[j].x1,s[j].y),pendiente(s[i].x1,s[i].y,s[j].x2,s[j].y)});
            // cout<<i<<" "<<j<<" "<<pendientes.back().first<<" "<<pendientes.back().second<<endl;
        }
    }
    vector<pair<ld,int>> events;
    for(int i = 0;i<pendientes.size();i++){ 
        events.push_back({-pendientes[i].first,1});
        events.push_back({-pendientes[i].second,-1});
    }
    set<ld> poss;
    int cont = 0;
    sort(events.begin(),events.end());
    for(int i = 0;i<events.size();i++){
        if(events[i].second == -1){
            cont--;
            if(cont == 0)poss.insert(events[i].first);
        }
        else{
            if(cont == 0)poss.insert(events[i].first);
            cont++;
        }
    }

    Hull CH1;
    Hullm CH2;
    for(int i = 0;i<n;i++){
        CH1.add(s[i].y,s[i].x2);
        CH2.add(s[i].y,s[i].x1);
    }
    ld ans = 1e15;
    if(poss.size()== 0){
        ans  = mxx-mnx;
    }
    // cout<<CH1.size()<<endl;
    
    for(auto c:poss){
        // cout<<c<<endl;
        ld mn = CH2.query(c);
        ld mx = CH1.query(c);
        // cout<<mn<<" "<<mx<<endl;
        ans = min(mx-mn,ans);
    }
    cout<<fixed<<setprecision(7);
    cout<<ans<<endl;
    return 0;
}
