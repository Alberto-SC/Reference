#include <iostream>
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const double INF = 1ll << 60;
const double ERROR = 1e-9;
const double M_2PI = 2.0 * M_PI;
#define EQ(a, b) (fabs((a) - (b)) < ERROR)
struct Punto{
	int x,y;
	Punto() : x(), y() {}
	Punto(int X,int Y): x(X),y(Y) {}
	bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
	bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
	}
	Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
  //Restar los vectores (o trasladarlos), tomando p como el origen.
  	Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
  //Obtener el vector opuesto.
  	Punto operator -() const { return Punto(-x, -y); }
  //Obtener el vector por un escalar.
  	Punto operator*( double c ) const { return Punto( x*c, y*c ); }
	double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }
	double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
	double Abs() const { return hypot(x, y); }
};
double Angulo(const Punto& a, const Punto& o, const Punto& b){
  Punto u(a - o), v(b - o);
  return acos( u.Dot(v) / (u.Abs() * v.Abs()));
}

typedef vector<Punto> Poligono;
struct Linea {
  Punto p, q;
  double a, b, c;
  Linea(const Punto& P, const Punto& Q)
    : p(P), q(Q), a(), b(), c() {
    // Asegura p como punto menor.
    if (q < p) swap(p, q);
  }
};
int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
  double ccw = (p-o).Cruz(q-o);
  return EQ(ccw, 0)? 0: (ccw < 0)? -1: 1;
}
bool PuntoEnRecta(const Punto& p, const Linea& r){
  return !ManoDerecha( r.p, r.q, p );
}
bool PuntoEnSegmento(const Punto& p, const Linea& s) {
  return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}


bool PuntoEnPerimetro(const Punto& p, const Poligono& P) {
  for (int i = 1; i < P.size(); ++i) {
    if( PuntoEnSegmento( p, Linea( P[i-1], P[i] ) ) ) return true;
  }
  return false;
}

int AngleSummation(const Punto& p, const Poligono& P) {
  if (PuntoEnPerimetro(p, P)) return -1;
  double angulo = 0;
  for (int i = 1; i < P.size(); ++i)
    angulo += ManoDerecha(p, P[i - 1], P[i]) * Angulo(P[i - 1], p,P[i]);
  return (fabs(angulo) > M_PI)? 1: 0;
}

int main(){
	int n,x,y;
	Poligono p;
	cin>>n;
	while(n){
		p.clear();
		for(int i = 0;i<n;i++){
			cin>>x>>y;
			p.push_back(Punto(x,y));
		}
		cin>>x>>y;
		int d = AngleSummation(Punto(x,y),p);
		if(d== -1 || d == 1)cout<<"T"<<endl;
		else cout<<"F"<<endl;
		cin>>n;
	}
	return 0;
}