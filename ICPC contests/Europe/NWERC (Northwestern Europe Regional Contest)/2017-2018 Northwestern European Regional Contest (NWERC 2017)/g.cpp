#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
using ld =  long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b
struct point{
	ld x, y;
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

	point rotate(const ld & a) const{return point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));}
	point perp() const{return point(-y, x);}
	ld ang() const{
		ld a = atan2l(y, x); a += le(a, 0) ? 2*pi : 0; return a;
	}
	ld dot(const point & p) const{return x * p.x + y * p.y;}
	ld cross(const point & p) const{return x * p.y - y * p.x;}
	ld norm() const{return x * x + y * y;}
	ld length() const{return sqrtl(x * x + y * y);}
	point unit() const{return (*this) / length();}

	bool operator==(const point & p) const{return eq(x, p.x) && eq(y, p.y);}
	bool operator!=(const point & p) const{return !(*this == p);}
	bool operator<(const point & p) const{return le(x, p.x) || (eq(x, p.x) && le(y, p.y));}
	bool operator>(const point & p) const{return ge(x, p.x) || (eq(x, p.x) && ge(y, p.y));}
	bool half(const point & p) const{return le(p.cross(*this), 0) || (eq(p.cross(*this), 0) && le(p.dot(*this), 0));}
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

int sgn(ld x){
	if(ge(x, 0)) return 1;
	if(le(x, 0)) return -1;
	return 0;
}

ld area(vector<point> & P){
	int n = P.size();
	ld ans = 0;
	for(int i = 0; i < n; i++){
		ans += P[i].cross(P[(i + 1) % n]);
	}
	return fabs(ans / 2);
}

bool pointInLine(const point & a, const point & v, const point & p){
	//line a+tv, point p
	return eq((p - a).cross(v), 0);
}

bool pointInSegment(const point & a, const point & b, const point & p){
	//segment ab, point p
	return pointInLine(a, b - a, p) && leq((a - p).dot(b - p), 0);
}

bool pointInPerimeter(const vector<point> & P, const point & p){
	int n = P.size();
	for(int i = 0; i < n; i++){
		if(pointInSegment(P[i], P[(i + 1) % n], p)){
			return true;
		}
	}
	return false;
}

bool crossesRay(const point & a, const point & b, const point & p){
	return (geq(b.y, p.y) - geq(a.y, p.y)) * sgn((a - p).cross(b - p)) > 0;
}

int pointInPolygon(const vector<point> & P, const point & p){
	if(pointInPerimeter(P, p)){
		return -1; //point in the perimeter
	}
	int n = P.size();
	int rays = 0;
	for(int i = 0; i < n; i++){
		rays += crossesRay(P[i], P[(i + 1) % n], p);
	}
	return rays & 1; //0: point outside, 1: point inside
}

vector<point> puntos;
vector<point> get_poligon(int faces,ld dist){
    vector<point> polygon;
    polygon.push_back(point(dist,0));
    ld rad = 360.0/faces;
    rad*=pi;
    rad/=180;
    for(int i =1;i<faces;i++){
        polygon.push_back(polygon[i-1].rotate(-rad));
    }
    return polygon;
}

int n;
bool check(int faces, ld dist,int type){
    vector<point> polygon = get_poligon(faces,dist);
    // for(auto c:polygon)cout<<c<<endl;
    int cont = 0;
    for(int i = 0;i<n;i++){
        if(pointInPolygon(polygon,puntos[i]) != 0)
            cont++;
        // cont+=pointInPolygon(polygon,puntos[i]);
    }
    // cout<<cont<<endl;
    if(!type)
        return cont == 0;
    return cont == n;
}

int main(){__
    cin>>n;
    puntos.resize(n);
    for(int i = 0;i<n;i++){
        cin>>puntos[i].x;
        cin>>puntos[i].y;
    }

    ld mx = 0.0;
    int faces = 0;
    for(int i = 3;i<=8;i++){
        ld l = 0,r = 2e7+7;
        int cont = 220;
        // cout<<"FACES: "<<i<<endl;
        while(cont--){
            ld m = (l+r)/2;
            // if(i == 4)cout<<m<<" "<<check(i,m,0)<<endl;
            if(check(i,m,0))
                l = m;
            else 
                r = m;
        }
        vector<point> inner = get_poligon(i,l);
        // cout<<l<<" "<<r<<endl;
        l = 0,r = 2e7+7;
        cont = 220;
        while(cont--){
            ld m = (l+r)/2;
            // if(i == 8)cout<<m<<" "<<check(i,m,1)<<endl;
            if(check(i,m,1))
                r = m;
            else 
                l = m;
        }
        // cout<<l<<" "<<r<<endl;
        vector<point> outter = get_poligon(i,r);
        // cout<<"INNER: "<<endl;
        // for(auto c:inner)cout<<c<<endl;
        // cout<<"Outter: "<<endl;
        // for(auto c:outter)cout<<c<<endl;
        // sort(inner.begin(),inner.end());
        // sort(outter.begin(),outter.end());
        ld res  = area(inner)/area(outter);
        // cout<<res<<endl;
        if(isgreater(res,mx)){
            mx = res;
            faces = i;
        }
    }
    cout<<fixed<<setprecision(8);
    cout<<faces<<" "<<mx<<endl;
    return 0;
}  

