#include <bits/stdc++.h>
using namespace std;
typedef long double Double;
typedef long long Long;
typedef pair<int, int> pii;

const Double INF = 1ll << 60;
const Double ERROR = 1e-9;
const Double M_2PI = 2.0 * M_PI;

#define EQ(a, b) (fabs((a) - (b)) < ERROR)
struct Punto {
  Double x, y;
  Punto() : x(), y() {}
  Punto(Double X, Double Y) : x(X), y(Y) {}
  bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  }
  bool operator<(const Punto & p)const {return y<p.y;}
  Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
  Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
  Punto operator -() const { return Punto(-x, -y); }
  Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
  Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
  Double Abs() const { return hypot(x, y); }
  Double Norm() const{ return x*x + y*y; }
  Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
  Double Dist2(const Punto& q ) const { return ( *this - q).Norm(); }
  Double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
  Double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }
};

struct Linea {
  Punto p, q;
  Double a, b, c;
  Linea() : p(), q(), a(), b(), c() {}
  Linea(Long A, Long B, Long C)
    : p(), q(), a(A), b(B), c(C) {
    if (EQ(a, 0)) {
      c /= -b; b = -1;
      p = Punto(0, c);
      q = Punto(1, c);
    } else if (EQ(b, 0)) {
      c /= -a; a = -1;
      p = Punto(c, 0);
      q = Punto(c, 1);
    } else {
      p = Punto(-c/a, 0);
      q = Punto(-(b+c)/a, 0);
    } if (q < p) swap(p, q);
  }
  Linea(const Punto& P, const Punto& Q)
    : p(P), q(Q), a(), b(), c() {
    // Asegura p como punto menor.
    if (q < p) swap(p, q);
    a = q.y - p.y;
    b = p.x - q.x;
    if (!a) c = p.y, b = -1;
    else if (!b) c = p.x, a = -1;
    else c = -a*p.x - b*p.y;
  }
  // PELIGRO! Ordena por ecuacion de recta.
  bool operator<(const Linea& cmp) const {
    if (!EQ(a, cmp.a)) return a < cmp.a;
    if (!EQ(b, cmp.b)) return b < cmp.b;
    return EQ(c, cmp.c)? false: c < cmp.c;
  }
};

Punto PuntoInterseccion(const Linea& l, const Linea& m) {
  Punto a = l.p, b = l.q, c = m.p, d = m.q;
  b = b-a; d = c-d; c =c-a;
  return a + b*(c.Cruz( d )/b.Cruz( d ));
}

Double Area(const Poligono& P) {
  Double area = 0;
  for (int i = 1; i < P.size(); ++i)
    area += P[i - 1].Cruz(P[i]);
  return fabs(area) / 2.0;
}


vector<Punto> ponints;
typedef vector<Punto> Poligono;
Double calular(int idxl,int idxh,int idxr){
    Poligono poly;
    if(ponints[idxl] < ponints[idxr]){
        Linea a =Linea(ponints[idxl],Punto(points[idxr].x,ponints[idxl].y));
        int idx = lower_bound(points.begin()+hole,points.begin()+idxr,Punto(0,points[idxl].y))-points.begin();
        Linea b;
    
        if(points[idx].y == points[idxl].y){
            for(int i = idxl;i<=idx;i++)
                poly.push_back(points[i]);
            poly.push_back(idxl);
        }
        else {
            b = Linea(points[idx],points[idx-1]);
            for(int i = idxl;i<idx;i++)
                poly.push_back(points[i]);
            Punto intx = PuntoInterseccion(a,b);
            poly.push_back(intx);
            poly.push_back(idxl);
        }
    }
    else {
        Linea a =Linea(ponints[idxr],Punto(points[idxl].x,ponints[idxr].y));
        int idx = lower_bound(points.begin()+idxl,points.begin()+hole,Punto(0,points[idxr].y),greater<int>())-points.begin();
        Linea b;
        if(points[idx].y == points[idxr].y){
            for(int i = idx;i<=idxr;i++)
                poly.push_back(points[i]);
            poly.push_back(idx);
        }
        else {
            b = Linea(points[idx],points[idx+1]);
            Punto intx = PuntoInterseccion(a,b);
            poly.push_back(intx);
            for(int i = idx;i<idxr;i++)
                poly.push_back(points[i]);
            poly.push_back(intx);
        }
    }
    return Area(poly);
}
int main(){
    int n,x,y;
    cin>>n;
    ponints.resize(n);
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        ponints[i] = Punto(x,y);
        
    }
    int i = 0,hole;
    Double ans = 0;
    int mxleft = ponints[i].y,mxrigth = -1;
    while(i<n){
        while(i+1<n && ponints[i].y<ponints[i+1].y){
            i++;
        }
        while(i+1<n && ponints[i].y>ponints[i+1].Y){
            i++;
        }
        hole = i;
        while(i+1<n && ponints[i].y<ponints[i+1].y){
            i++;
        }
        mxrigth= i;
        ans+=calular(mxleft,hole,mxrigth);
        mxleft = mxrigth;
    }  
    return 0;
}