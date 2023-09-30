#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;
const double INF = 1ll << 60;
const double ERROR = 1e-9;
const double M_2PI = 2.0 * M_PI;

// Tolerancia a flotantes
#define EQ(a, b) (fabs((a) - (b)) < ERROR)
struct Punto {
  double x, y;
  Punto() : x(), y() {}
  Punto(double X, double Y) : x(X), y(Y) {}
  bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  }
  Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
  Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
  Punto operator -() const { return Punto(-x, -y); }
  double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }
};
Punto p0;
typedef vector<Punto> Poligono;
Poligono convexh;


int ManoDerecha(const Punto& o, const Punto& p,	 const Punto& q) {
  double ccw = (p-o).Cruz(q-o);
  return EQ(ccw, 0)? 0: (ccw < 0)? -1: 1;
}

int distSq(Punto p1, Punto p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
bool compare (Punto p1,Punto p2) { 
	int o = ManoDerecha(p0,p1,p2);
	if(o == 0)
		return (distSq(p0,p2) >= distSq(p0,p1))? 0 :1;
	return (o == 1)? 0:1;}

double Area(const Poligono& P) {
  double area = 0;
  for (int i = 1; i < P.size(); ++i)
    area += P[i - 1].Cruz(P[i]);
  return fabs(area) / 2.0;
}

Punto next(stack<Punto> &S){
	Punto p = S.top();
      S.pop();
      Punto res = S.top();
      S.push(p);
      return(res);
}
void convexHull(Poligono P){
   int n = P.size();
   int i, m, t;
   m = 0;
   convexh.resize(n);
   for(i = 0; i < n; i++) {
        while(m >= 2 && ManoDerecha(convexh[m-2], convexh[m-1], P[i]) <= 0)
            m--;
        convexh[m++] = P[i];
    }
    for(i = n-1, t = m+1; i >= 0; i--) {
        while(m >= t && ManoDerecha(convexh[m-2], convexh[m-1], P[i]) <= 0)
            m--;
        convexh[m++] = P[i];
    }
    convexh.resize(m);
}

int main(){
	int n,x,y,cont = 1;
	cin>>n;
	Poligono pl;
	while(n!= 0){
		convexh.clear();
		pl.clear();
		for(int i = 0;i<n;i++){
			cin>>x>>y;
			pl.push_back(Punto(x,y));
		}
		pl.push_back(pl[0]); 		
		double areap,areac;
		areap = Area(pl);
   		sort(pl.begin(),pl.end());
		convexHull(pl);
		areac = Area(convexh);
		//cout<<"Area poligono: "<<areap<<endl;
		//cout<<"Area convex: "<<areac<<endl;
		cout<<"Tile #"<<cont<<endl;
		cout<< std::fixed;
		cout<< std::setprecision(2);
		cout<<"Wasted Space = "<<((areac-areap)*100)/areac<<" %"<<endl;
		cont++;
		cout<<endl;
		cin>>n;
	}



}