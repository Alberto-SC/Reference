#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
const double ERROR = 1e-9;
#define EQ(a, b) (fabs((a) - (b)) < ERROR)

struct Punto {
  double x, y;
  Punto() : x(), y() {}
  Punto(double X, double Y) : x(X), y(Y) {}
  // Izquierda a derecha, abajo a arriba.
  bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  }
  //Sumar los vectores actual y q.
  Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
  //Restar los vectores (o trasladarlos), tomando p como el origen.
  Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
};



  
int main(){
	vector<Punto> p;
	double x,y;
	cout <<std::fixed;
	cout <<std::setprecision(3);
	while(cin>>x>>y){
	p.clear();
	p.push_back(Punto(x,y));
	for(int i =0 ;i<3;i++){
		cin>>x>>y;
		p.push_back(Punto(x,y));
	}
	Punto a;
	if(p[0] == p[2])
		a =(p[1]+p[3])-p[0],cout<<a.x<<" "<<a.y<<endl;
	else if(p[0] == p[3])
		a =(p[1]+p[2])-p[0],cout<<a.x<<" "<<a.y<<endl;
	else if(p[1] == p[2])
		a =(p[0]+p[3])-p[1],cout<<a.x<<" "<<a.y<<endl;
	else
		a =(p[0]+p[2])-p[1],cout<<a.x<<" "<<a.y<<endl;
	}
}