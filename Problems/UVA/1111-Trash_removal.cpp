#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long double Double;
const Double ERROR  = 1e-9;
#define EQ(a, b) (fabs((a) - (b)) < ERROR)
struct Punto{
	int x,y;
	Punto(int X,int Y): x(X),y(Y){}
	bool operator<(const Punto& q)const{
		if EQ(!x,q.x) return x<q.x;
		return EQ(y, q.y)? false: y < q.y;
	}
	Punto operator-(const Punto& q)const {return Punto(x-q.x,y-q.y);}
    Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
	Double cruz(const Punto& q) const{return x*q.y- y*q.x;}
	Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
	Double abs() const{return hypot(x,y);} 
	Double dist(const Punto& q) const{return (*this-q).abs();}
	Double dot(const Punto& q)const {return x* q.x + y * q.y;}
	Double norm()const {return x*x +y*y;}
};
typedef vector<Punto> Poligono;


int orientation(const Punto& o, const Punto& p ,const Punto& q){
	Double ccw = (p-o).cruz(q-o);
	return EQ(ccw,0)? 0: (ccw<0)? -1:1;
}
Poligono convexhull(Poligono & p){
	Poligono h;
	int k = 0;
	int n = p.size();
	h.resize(2*n,Punto(0,0));
	sort(p.begin(),p.end());
	for(int i = 0;i<n;i++){
		while(k>= 2 && orientation(h[k-2], h[k-1], p[i]) <= 0)k--;
		h[k++] = p[i];
	}
	for(int i = n-1 , t = k+1;i>0;i--){
		while(k>=t && orientation(h[k-2] , h[k-1], p[i-1]) <= 0)k--;
		h[k++] = p[i-1];
	}
	return h;
}
struct Linea{
	Punto p;
	Punto q;
	Linea(Punto P, Punto Q): p(P), q(Q){
		if(q<P);
		swap(p,q);
	}
};
Punto ProyeccionEnRecta(const Punto& v, const Linea& r) {
  return r.p + ( r.q - r.p ) *  (( v - r.p ).dot( r.q - r.p )/( r.q  - r.p ).norm());
}

// Distancia entre un punto p y una recta r.
Double DistanciaPuntoRecta(const Punto& p, const Linea& r) {
  return p.dist(ProyeccionEnRecta(p, r));
}
Double diameterAndWidth(Poligono & P){
  int n = P.size(), k = 0;
  auto dot = [&](int a, int b){return (P[(a+1)%n]-P[a]).dot(P[(b+1)%n]-P[b]);};
  auto cruz = [&](int a, int b){return (P[(a+1)%n]-P[a]).cruz(P[(b+1)%n]-P[b]);};
  Double diameter = numeric_limits<Double>::min();
  Double width = numeric_limits<Double>::max();
  while(dot(0, k) > 0) k = (k+1) % n;
  	for(int i = 0; i < n; ++i){
    	while(cruz(i, k) > 0) k = (k+1) % n;
    	//pair: (i, k)
    	//diameter = max(diameter, (P[k] - P[i]).length());
    	width = min(width, DistanciaPuntoRecta(P[k],Linea(P[i],P[i+1%n])));
  }
  return  width;
}

int main(){
	int n,x,y,cont = 1;
	cin>>n;
	Poligono p;
	while(n){
		p.clear();
		for(int i = 0;i<n;i++){
			cin>>x>>y;
			p.push_back(Punto(x,y));
		}
		Poligono h = convexhull(p);
	    Double an = 1e10;
		an = diameterAndWidth(h);
		cout<<"Case "<<cont<<": ";
		cont++;
		an *= 100; 
		an = ceil(an);
		an /= 100; 
		std::cout << std::fixed;
   		std::cout << std::setprecision(2);
		cout<<an<<endl;
		cin>>n;
	}
	return 0;
}