#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const double INF = 1ll << 60;
const double ERROR = 1e-9;
const double M_2PI = 2.0 * M_PI;

// Tolerancia a flotantes
#define EQ(a, b) (fabs((a) - (b)) < ERROR)
struct Punto{
  double x,y;
  Punto() : x(), y() {}
  Punto(double X, double Y) : x(X), y(Y) {}
    bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
  double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }
};

int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
  double ccw = (p-o).Cruz(q-o);
  return EQ(ccw, 0)? 0: (ccw < 0)? -1: 1;
}

int  convexHull(Punto P[],int n,Punto convexh[]){
   sort(P,P+n);
   int i, m, t;
   m = 0;
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
    return m-1;
}


int main(){
	int n,na;
  double per,p;
  scanf("%d",&n);
    while(n--){
      scanf("%lf %d",&p,&na);
      Punto po[1005],convexh[1005]; 
      for(int j = 0;j<na;j++)
        scanf("%lf %lf",&po[j].x,&po[j].y);
      int m = convexHull(po,na,convexh);
      per = 0;
      for(int i = 0; i < m; i++) {
            per += sqrt(pow(convexh[i].x-convexh[i+1].x, 2)+pow(convexh[i].y-convexh[i+1].y, 2));
        }
      if(per > p)
         printf("%.5f\n",per);
      else 
         printf("%.5f\n",p);
	}

}