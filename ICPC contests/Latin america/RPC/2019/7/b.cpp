#include <bits/stdc++.h>
using namespace std;
#define dot(a,b) ((conj(a)*(b)).real())
#define lengthSqr(v) (dot(v,v))
#define angle(v) (atan2((v).imag(),(v).real()))
const double eps = 1e-9;
typedef complex<double> point;

#define IN 1
#define OUT 2
#define BOUNDRY 3

int circleLineIntersection(const point& p0, const point& p1, const point& cen, double rad, point& r1, point & r2) {
	double a, b, c, t1, t2;
	a = dot(p1 - p0, p1 - p0);
	b = 2 * dot(p1 - p0, p0 - cen);
	c = dot(p0-cen,p0-cen) - rad * rad;
	double det = b * b - 4 * a * c;
	int res;
	if (fabs(det) < eps)
		det = 0, res = 1;
	else if (det < 0)
		res = 0;
	else
		res = 2;
	det = sqrt(det);
	t1 = (-b + det) / (2 * a);
	t2 = (-b - det) / (2 * a);
	r1 = p0 + t1 * (p1 - p0);
	r2 = p0 + t2 * (p1 - p0);
	return res;
}

int circlePoint(const point & cen, const double & r, const point& p) {
	long lensqr = lengthSqr(p-cen);
	if (fabs(lensqr - r * r) < eps)
		return BOUNDRY;
	if (lensqr < r * r)
		return IN;
	return OUT;
}

int tangentPoints(const point & cen, const double & r, const point& p, point &r1, point &r2) {
	int s = circlePoint(cen, r, p);
    if (s != OUT) {
		r1 = r2 = p;
		return s == BOUNDRY;
	}
	point cp = p-cen;
	double h = (double)hypot(cp.imag(),cp.real());
	double a = acos(r / h);
    
	cp = ((cp)/(double)hypot(cp.imag(),cp.real())) * r;
     
	r1 = ((cp)*exp(point(0,(a)))) + cen;
	r2 = ((cp)*exp(point(0,(-a)))) + cen;
	return 2;
}

// point cen;
// double r;

double calcArc(point p1, point p2,point cen,const double & r) {
	double d = (double)hypot((p2-p1).imag(),(p2-p1).real());
	double ang = (angle(p1-cen) - angle(p2-cen)) * 180 / M_PI;
	if (ang < 0)
		ang += 360;
	ang = min(ang, 360 - ang);
	return r * ang * M_PI / 180;
}

int main(){
    int x, y;
	point src, snk,cen;
    double r,ans;
	cin>>x>>y;
	src = point(x,y);
	cin >> x >> y;
	snk = point(x,y);
	cin>>x>>y>>r;
	cin>>x>>y>>r;
	cen=point(x,y);
	double res = 0;
	point p1, p2, p3, p4;
    cout<<fixed<<setprecision(10);
    tangentPoints(cen,r,src,p1,p2);
    tangentPoints(cen,r,snk,p3,p4);
    ans = DBL_MAX;
    ans = min(ans, (double)hypot((p1-src).imag(),(p1-src).real()) + calcArc(p1, p3,cen,r) + (double)hypot((snk-p3).imag(),(snk-p3).real()));
    ans = min(ans, (double)hypot((p1-src).imag(),(p1-src).real()) + calcArc(p1, p4,cen,r) + (double)hypot((snk-p4).imag(),(snk-p4).real()));
    ans = min(ans, (double)hypot((p2-src).imag(),(p2-src).real()) + calcArc(p2, p3,cen,r) + (double)hypot((snk-p3).imag(),(snk-p3).real()));
    ans = min(ans, (double)hypot((p2-src).imag(),(p2-src).real()) + calcArc(p2, p4,cen,r) + (double)hypot((snk-p4).imag(),(snk-p4).real()));
    cout<<ans<<endl;
    return 0;
}