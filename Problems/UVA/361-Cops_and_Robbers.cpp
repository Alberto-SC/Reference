#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const double INF = 1ll << 60;
const double ERROR = 1e-9;
const double M_2PI = 2.0 * M_PI;
#define EQ(a,b) (fabs((a)-(b)) < ERROR)

struct Punto{
	double x,y;
	Punto(double X,double Y): x(X),y(Y){}
	bool operator<(const Punto &q)const{
		if(!EQ(x,q.x))return x<q.x;
		return EQ(y,q.y)? false: y<q.y;
	}
	bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  	}
  	Punto operator+(const Punto &q) const{return Punto(x+q.x,y+q.y);}
  	Punto operator-(const Punto &q) const{return Punto(x-q.x,y-q.y);}
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
  Linea(const Punto& P, const Punto& Q): p(P), q(Q){if (q < p) swap(p, q);}
};

int ManoDerecha(const Punto& o, const Punto& p, const Punto& q){
	double ccw = (p-o).Cruz(q-o);
  	return EQ(ccw, 0)? 0: (ccw < 0)? -1: 1;
}

bool PuntoEnRecta(const Punto& p, const Linea& r){
  return !ManoDerecha(r.p,r.q,p);
}

bool PuntoEnSegmento(const Punto& p, const Linea& s) {
  return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}

bool PuntoEnPerimetro(const Punto& p,const Poligono& P){
	for(int i = 1;i<P.size();i++)
		if(PuntoEnSegmento(p,Linea(P[i],P[i-1]))) return true;
	return false;
}

int AngleSummation(const Punto& p, const Poligono& P) {
	if(P.size()<3)return 0;
  if (PuntoEnPerimetro(p, P)) return -1;
  double angulo = 0;
  for (int i = 1; i < P.size(); ++i)
    angulo += ManoDerecha(p, P[i - 1], P[i]) * Angulo(P[i - 1], p,P[i]);
  return (fabs(angulo) > M_PI)? 1: 0;
}

int main(){
	int c,r,o,x,y,cont = 1;
	cin>>c>>r>>o;
	Poligono pc,pr;
	while(c||r||o){

		pc.clear();
		pr.clear();
		for(int i = 0;i<c;i++){
			cin>>x>>y;
			pc.push_back(Punto(x,y));
		}
		for(int i = 0;i<r;i++){
			cin>>x>>y;
			pr.push_back(Punto(x,y));
		}
		cout<<"Data set "<<cont<<":"<<endl;
		for(int i = 0;i<o;i++){
			bool bpc = false;
			cin>>x>>y;
			int a = fabs(AngleSummation(Punto(x,y),pc));
			if(a == 1) bpc = true;
			a+= fabs(AngleSummation(Punto(x,y),pr));
			cout<<"     Citizen at ("<<x<<","<<y<< ") is";

		    if(a == 0||a == 2)cout<<" neither."<<endl;
			else if(a == 1){
				if(bpc)cout<<" safe."<<endl;
				else cout<<" robbed."<<endl;
			}
		}
		cout<<endl;
		cont++;
		cin>>c>>r>>o;
	}

}
