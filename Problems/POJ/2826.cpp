#include <algorithm>
#include <iostream> 
#include <complex> 
#include <vector>
#include <set>
#include <iomanip>    
#include <cmath>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define x real()
#define y imag()

typedef double T;
typedef complex<T> pt;

T dot(pt v, pt w) {return (conj(v)*w).x;}
T cross(pt v, pt w) {return (conj(v)*w).y;}
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

T area(vector<pt> P){
 	int n = P.size();
	T ans = 0;
	for(int i = 0; i<n; i++){
		ans += cross(P[i],P[(i + 1) % n]);
	}
	return abs(ans / 2);
}

bool inDisk(pt a,pt b,pt p){
    return dot(a-p,b-p)<=0;
}

bool pointInSegment(pt a,pt b,pt p){
    return inDisk(a,b,p) && orient(a,b,p)== 0;
}

bool properIntersectionOfSegments(pt a, pt b, pt c, pt d, pt &out) {
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

vector<pt> intersectSegments(const pt a, const  pt b, const pt c, const  pt d) {
    pt out;
    vector<pt> s;
    if (properIntersectionOfSegments(a,b,c,d,out)) {
        s.push_back(out);
        return s;
    }
    if (pointInSegment(a,b,c)) s.push_back(c);
    if (pointInSegment(a,b,d)) s.push_back(d);
    return s;
}

double angle(pt v, pt w) {
    double cosTheta = dot(v,w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}


int main(){
    int t;
    cin>>t;
    while(t--){
        pt a,b,c,d;
        T x0,y0,x1,y1;
        T a0,b0,a1,b1;
        cin>>a0>>b0>>a1>>b1;
        cin>>x0>>y0>>x1>>y1;
        a = {x0,y0};
        b = {x1,y1};
        c = {a0,b0};
        d = {a1,b1};

        pt intersect;
        cout<<fixed<<setprecision(2);
        pt px,py;
        if(a.y>b.y)px = a;
        else px = b;
        if(c.y>d.y)py = c;
        else py = d;
        auto s = intersectSegments(a,b,c,d);
        if(s.size()==0 || s.size()==2){
            cout<<0.00<<endl;
            continue;
        }
        else intersect = s[0];

        if(intersect.y> px.y || intersect.y >py.y){
            cout<<0.0<<endl;
            continue;
        }
        if(px.y<py.y){
            pt l = {-10000,px.y};
            pt r = {10000,px.y};
            pt in2;
            auto st = intersectSegments(l,r,c,d);
            in2  = *st.begin();
            if(angle(in2-px,py-px)>=MATH_PI/2.0)cout<<0.0<<endl;
            else cout<<area({intersect,px,in2,intersect})<<endl;
        }
        else{
            pt l = {-10000,py.y};
            pt r = {10000,py.y};
            pt in2;

            auto st = intersectSegments(l,r,a,b);
            in2 = *st.begin();
            if(angle(in2-py,px-py)>=MATH_PI/2.0)cout<<0.0<<endl;
            else cout<<area({intersect,py,in2,intersect})<<endl;
        }
    }
    return 0;
}