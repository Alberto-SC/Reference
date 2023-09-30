#include <bits/stdc++.h>
using namespace std;

typedef long double Double;
typedef long long Long;
typedef pair<int, int> pii;

const double PI = acos(-1); 
const Double INF = 1ll << 60;
const Double ERROR = 1e-9;
const Double M_2PI = 2.0 * M_PI;

// Tolerancia a flotantes
#define EQ(a, b) (fabs((a) - (b)) < ERROR)

// Punto en 2D.
struct Punto {
  Double x, y;
  Punto() : x(), y() {}
  Punto(Double X, Double Y) : x(X), y(Y) {}
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
  //Obtener el vector opuesto.
  Punto operator -() const { return Punto(-x, -y); }
  //Obtener el vector por un escalar.
  Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
  //Obtener el vector dividido por un escalar.
  Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
  //Magnitud del vector.
  Double Abs() const { return hypot(x, y); }
  //Magnitud elevada al cuadrado del vector.
  Double Norm() const{ return x*x + y*y; }
  //Distancia entre el punto actual y q.
  Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
  //Distancia elevada al cuadrado entre el punto actual y q.
  Double Dist2(const Punto& q ) const { return ( *this - q).Norm(); }
  //Producto punto entre el punto actual y q.
  Double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
  //Producto cruz entre el punto actual y q.
  Double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }

  //Rotar 90 grados en CCW.
  Punto rot90() const { return Punto(-y, x); }

  //Rotar t radianes en cw respecto al origen.
  Punto RotarCW(const Double& t) const {
    return Punto( x*cos(t) + y*sin(t),
            y*cos(t) - x*sin(t));
  }
  //Rotar t radianes en ccw respecto al origen.
  Punto RotarCCW(const Double& t) const {
    return Punto( x*cos(t) - y*sin(t), 
            y*cos(t) + x*sin(t));
  }
};
int n;
typedef vector<Punto> Poligono;
Poligono points;
double RotatingCalipers( Poligono &P ){
    int k = 1, i = P.size()-2, j = 0;
    while( fabs( ( P[j] - P[i] ).Cruz( P[k+1] - P[i] ) ) > 
      fabs( ( P[j] - P[i] ).Cruz( P[k] - P[i] )) ) k++;

    i = 0, j = k;
    vector<pair<int,int>> res;
    while( i <= k && j < P.size()-1 ){
      res.push_back( pii(i,j) );
      while( j < P.size()-1 && fabs( ( P[i+1] - P[i] ).Cruz( P[j+1] - P[i] ) ) >   fabs( ( P[i+1] - P[i] ).Cruz( P[j] - P[i] ) ) ){
        j++;
        res.push_back( pii( i, j ));
      }
      i++;
    }
    Double mx = 10000000;
    for(int i = 0;i<res.size();i++){
      cout<<res[i].first<<" "<<res[i].second<<endl;
      Punto a = P[res[i].first];
      Punto b = P[res[i].second];
      mx = min(a.Dist(b),mx);
    }
    return mx;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        n*=2;
        points.resize(n);
        points[0] = Punto(1.0,1.0);
        double rotar = (2*PI)/n;
        // points[0] = points[0].RotarCCW(rotar/2);

        for(int i = 1;i<n;i++){
          points[i] = points[i-1].RotarCCW(rotar);
          // points[i] = RotarCCW(rotar/2);
        }
        cout<<points[0].Dist(points[1])<<endl;
        for(int i = 0;i<n;i++)cout<<points[i].x<<" "<<points[i].y<<endl;
        cout<<RotatingCalipers(points)/2<<endl;
        // double ans = rotate_caliper();
        // cout<<ans<<endl;
    }
    return 0;
}