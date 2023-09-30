#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
typedef long long int lli;

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool ge(ld a, ld b){return a-b > eps;}        //a > b

struct point{
	ld x,y;
	
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y);}
	point operator*(const ld & k) const{return point(x * k, y * k);}
	point operator/(const ld & k) const{return point(x / k, y / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const ld & p){*this = *this * p; return *this;}
	point operator/=(const ld & p){*this = *this / p; return *this;}

	ld cross(const point &p) const{
		return x*p.y - y*p.x;
	}
	ld dot(const point &p) const{
		return x*p.x + y*p.y;
	}
	ld norm() const{
		return x*x + y*y;
	}
	ld length() const{
		return sqrtl(x * x + y * y);
	}
	point unit() const{
		return (*this)/length();
	}
};

bool pointInLine(const point &a, const point &v, const point &p){
	return eq((p-a).cross(v), 0);
}

bool pointInSegment(const point &a, const point &b, const point &p){
	return pointInLine(a, b-a, p) && leq((a-p).dot(b-p), 0);
}

vector<point> intersectLineCircle(const point &a, const point &v, const point &c, ld r){
	ld h2 = r*r - v.cross(c-a) * v.cross(c-a) / v.norm();
	point p = a + v * v.dot(c-a) / v.norm();

	if(eq(h2,0)){
		return {p};
	}else if(le(h2,0)){
		return {};
	}else{
		point u = v.unit() * sqrt(h2);
		return {p-u, p+u};
	}
}

vector<point> intersectSegmentCircle(const point &a, const point &b, const point &c, ld r){
	vector<point> P = intersectLineCircle(a, b-a, c, r), ans;
	for(const point &p:P){
		if(pointInSegment(a, b, p)){
			ans.push_back(p);
		}
	}
	return ans;
}

int pointInCircle(const point & c, ld r, const point & p){
	ld l = (p-c).length() - r;
	return (le(l, 0)?1:(eq(l, 0)?-1:0));
}

int sgn(ld x){
	if(ge(x, 0)) return 1;
	if(le(x, 0)) return -1;
	return 0;
}

ld signed_angle(const point & a, const point & b){
	return sgn(a.cross(b)) * acosl(a.dot(b) / (a.length() * b.length()));
}

ld intersectPolygonCircle(const vector<point> & P, const point & c, ld r){
	int n = P.size();
	ld ans = 0;
	for(int i = 0; i < n; ++i){
		point p = P[i], q = P[(i+1)%n];
		bool p_inside = (pointInCircle(c, r, p) != 0);
		bool q_inside = (pointInCircle(c, r, q) != 0);
		if(p_inside && q_inside){
			ans += (p - c).cross(q - c);
		}else if(p_inside && !q_inside){
			point s1 = intersectSegmentCircle(p, q, c, r)[0];
			point s2 = intersectSegmentCircle(c, q, c, r)[0];
			ans += (p - c).cross(s1 - c) + r*r * signed_angle(s1 - c, s2 - c);
		}else if(!p_inside && q_inside){
			point s1 = intersectSegmentCircle(c, p, c, r)[0];
			point s2 = intersectSegmentCircle(p, q, c, r)[0];
			ans += (s2 - c).cross(q - c) + r*r * signed_angle(s1 - c, s2 - c);
		}else{
			auto info = intersectSegmentCircle(p, q, c, r);
			if(info.size() <= 1){
				ans += r*r * signed_angle(p - c, q - c);
			}else{
				point s2 = info[0], s3 = info[1];
				point s1 = intersectSegmentCircle(c, p, c, r)[0];
				point s4 = intersectSegmentCircle(c, q, c, r)[0];
				ans += (s2 - c).cross(s3 - c) + r*r * (signed_angle(s1 - c, s2 - c) + signed_angle(s3 - c, s4 - c));
			}
		}
	}
	return abs(ans)/2;
}

int main(){
	ld x,y,r,d;
	cin >> x >> y >> r;
	point c = point(x,y);

	cin >> x >> y >> d;
	point e = point(x,y);
	point f = point(x+d,y);
	point g = point(x+d,y+d);
	point h = point(x,y+d);

	if(ge(intersectPolygonCircle({e,f,g,h}, c, r), 0)){
		cout << 2 << endl;
		return 0;
	}

	int tan = 0;
	tan += (pointInCircle(c, r, e) == -1)?1:0;
	tan += (pointInCircle(c, r, f) == -1)?1:0;
	tan += (pointInCircle(c, r, g) == -1)?1:0;
	tan += (pointInCircle(c, r, h) == -1)?1:0;
	tan += (intersectSegmentCircle(e, f, c, r).size() == 1)?1:0;
	tan += (intersectSegmentCircle(f, g, c, r).size() == 1)?1:0;
	tan += (intersectSegmentCircle(g, h, c, r).size() == 1)?1:0;
	tan += (intersectSegmentCircle(h, e, c, r).size() == 1)?1:0;
	if(tan != 0){
		cout << 1 << endl;
		return 0;
	}

	cout << 0 << endl;
	return 0;
}