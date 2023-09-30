#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define x real()
#define y imag()

typedef double T;
typedef complex<T> pt;

//Basics
T dot(pt v, pt w) {return (conj(v)*w).x;}  // v.x*w.x + v.y*w.y;
T cross(pt v, pt w) {return (conj(v)*w).y;} // {v.x*w.y - v.y*w.x;}
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

// 0 if is colinear (or are in the line AB), >0 if is left turn , <0 if is a right turn 
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}


//Translations 
pt translate(pt v,pt p){return p+v;}
pt scale(pt c ,double factor,pt p){return c + (p-c)*factor;}
pr rotate(pt p,double a){return p * polar(1.0,a);}
pt perp(pt p){return {-p.y,p.x};} //rotate 90°
pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq) {
    return fp + (r-p) * (fq-fp) / (q-p);
}
bool isPerp(pt v, pt w) {return dot(v,w) == 0;}

double angle(pt v, pt w) {
    double cosTheta = dot(v,w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}
// Angle betwen the lines AB and AC in oriented way 
double orientedAngle(pt a, pt b, pt c) {
    if (orient(a,b,c) >= 0)
    return angle(b-a, c-a);
    else
    return 2*M_PI - angle(b-a, c-a);
}

// Check if a point is betwen the angle formed by the lines AB ,AC
bool inAngle(pt a, pt b, pt c, pt p) {
    assert(orient(a,b,c) != 0);
    if (orient(a,b,c) < 0) swap(b,c);
    return orient(a,b,p) >= 0 && orient(a,c,p) <= 0;
}

// If we want some vector v to be the first angle 
pt v = {1e9,0}; // diferent from {0,0}
bool half(pt p) {
    return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) <0);
}
// bool half(pt p) { // true if in blue half
//     assert(p.x != 0 || p.y != 0); // the argument of (0,0) is undefined
//     return p.y > 0 || (p.y == 0 && p.x < 0);
// }

void polarSortAround(pt o, vector<pt> &v) {
    sort(v.begin(), v.end(), [](pt v, pt w) {
        return make_tuple(half(v-o), 0) <make_tuple(half(w-o), cross(v-o, w-o));
    });
}

struct line {
    pt v; T c;
    pt p,q;
    // T a,b,c;
    // From direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}
    // From equation ax+by=c
    line(T a, T b, T c) : v({b,-a}), c(c) {}
    // From points P and Q
    line(pt p, pt q) : v(q-p), c(cross(v,p)) ,p(p),q(q){}
    // Will be defined later:
    // - these work with T = int
    T side(pt p) {return cross(v,p)-c;}
    double dist(pt p) {return abs(side(p)) / abs(v);}
    double sqDist(pt p) {return side(p)*side(p) / (double)sq(v);}
    line perpThrough(pt p) {return {p, p + perp(v)};}
    bool cmpProj(pt p, pt q) {
        return dot(v,p) < dot(v,q);
    }
    line translate(pt t) {return {v, c + cross(v,t)};}
    // - these require T = double
    line shiftLeft(double dist) {return {v, c + dist*abs(v)};}

    pt proj(pt p) {return p - perp(v)*side(p)/sq(v);}
    pt refl(pt p) {return p - perp(v)*2*side(p)/sq(v);}
}

//Mapping pendients 
map<pair<int,int>,map<int,set<int>> mp;
void add(pt a,pt b,int ida,int idb){
    int A = a.y-b.y;
    int B = a.x-b.x;
    int gcd = __gcd(A,B);
    A/=gcd;
    B/=gcd;
    C = (a.x*A) - (a.y*B);
    mp[{A,B}][C].insert(ida);
    mp[{A,B}][C].insert(idb);
}

bool intersect(line l1, line l2, pt &out) {
    T d = cross(l1.v, l2.v);
    if (d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point
    coordinates
    return true;
}

// Is a line that forms equal angles with l1 and l2
line bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
    double sign = interior ? 1 : -1;
    return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign,
    l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
}

// Segments 
// Check if a point are int the circle of radius AB , if the angle is less of 90° is inside
bool pointInDisk(pt a, pt b, pt p) {
    return dot(a-p, b-p) <= 0;
}

bool pointInSegment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && pointInDisk(a,b,p);
}


bool properInter(pt a, pt b, pt c, pt d, pt &out) {
    double oa = orient(c,d,a),
    ob = orient(c,d,b),
    oc = orient(a,b,c),
    od = orient(a,b,d);

    if (oa*ob < 0 && oc*od < 0) {
    out = (a*ob - b*oa) / (ob-oa);
    return true;
    }
    return false;
}

struct cmpX {
    bool operator()(pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    }
};

set<pt,cmpX> inters(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a,b,c,d,out)) return {out};
    set<pt,cmpX> s;
    if (onSegment(c,d,a)) s.insert(a);
    if (onSegment(c,d,b)) s.insert(b);
    if (onSegment(a,b,c)) s.insert(c);
    if (onSegment(a,b,d)) s.insert(d);
    return s;
}

double closestDistanceSegmentPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a,b);
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) // if closest to projection
        return l.dist(p); // output distance to line
    }
    return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}

double closestDistanceSegmentSegment(pt a, pt b, pt c, pt d) {
    pt dummy;
    if (properInter(a,b,c,d,dummy))
    return 0;
    return min({segPoint(a,b,c), segPoint(a,b,d),
    segPoint(c,d,a), segPoint(c,d,b)});
}

/*+ Polygons */

double areaTriangle(pt a, pt b, pt c) {
    return abs(cross(b-a, c-a)) / 2.0;
}

double areaPolygon(vector<pt> p) {
    double area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++) {
    area += cross(p[i], p[(i+1)%n]); // wrap back to 0 if i == n-1
    }
    return abs(area) / 2.0;
}

bool above(pt a, pt p) {
    return p.y >= a.y;
}
// check if [PQ] crosses ray from A
bool crossesRay(pt a, pt p, pt q) {
    return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}

// if strict, returns false when A is on the boundary
bool inPolygon(vector<pt> p, pt a, bool strict = true) {
    int numCrossings = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (pointInSegment(p[i], p[(i+1)%n], a))
            return !strict;
        numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
    }
    return numCrossings & 1; // inside if odd number of crossings
}

// amplitude travelled around point A, from P to Q
double angleTravelled(pt a, pt p, pt q) {
    double ampli = angle(p-a, q-a);
    if (orient(a,p,q) > 0) return ampli;
    else return -ampli;
}

double angleTravelled(pt a, pt p, pt q) {
    // remainder ensures the value is in [-pi,pi]
    return remainder(arg(q-a) - arg(p-a), 2*M_PI);
}

int windingNumber(vector<pt> p, pt a) {
    double ampli = 0;
    for (int i = 0, n = p.size(); i < n; i++)
    ampli += angleTravelled(a, p[i], p[(i+1)%n]);
    return round(ampli / (2*M_PI));
}

/*+ Circles */

pt circumCenter(pt a, pt b, pt c) {
    b = b-a, c = c-a; // consider coordinates relative to A
    assert(cross(b,c) != 0); // no circumcircle if A,B,C aligned
    return a + perp(b*sq(c) - c*sq(b))/cross(b,c)/2;
}

int circleLine(pt o, double r, line l, pair<pt,pt> &out) {
    double h2 = r*r - l.sqDist(o);
    if (h2 >= 0) { // the line touches the circle
    pt p = l.proj(o); // point P
    pt h = l.v*sqrt(h2)/abs(l.v); // vector parallel to l, of
    length h
    out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}

int circleCircle(pt o1, double r1, pt o2, double r2, pair<pt,pt> &out) {
    pt d=o2-o1; double d2=sq(d);
    if (d2 == 0) {assert(r1 != r2); return 0;} // concentric circles
    double pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
    double h2 = r1*r1 - pd*pd/d2; // = hˆ2
    if (h2 >= 0) {
    pt p = o1 + d*pd/d2, h = perp(d)*sqrt(h2/d2);
    out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}

int tangents(pt o1, double r1, pt o2, double r2, bool inner, vector<pair<pt,pt>> &out) {
    if (inner) r2 = -r2;
    pt d = o2-o1;
    double dr = r1-r2, d2 = sq(d), h2 = d2-dr*dr;
    if (d2 == 0 || h2 < 0) {assert(h2 != 0); return 0;}
    for (double sign : {-1,1}) {
    pt v = (d*dr + perp(d)*sqrt(h2)*sign)/d2;
    out.push_back({o1 + v*r1, o2 + v*r2});
    }
    return 1 + (h2 > 0);
}



int main(){__
    pt p{3,-4};
    cout<<p.x<<" "<<p.y<<endl;
    cout<<p<<endl;
    pt a{3,1}, b{1,-2};
    a += 2.0*b;
    cout<<a<<endl;
    return 0;
}