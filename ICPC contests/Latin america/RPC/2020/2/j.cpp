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

const double inf = 10000000.0;
int main(){
    int n,m;
    cin>>m;
    vector<int> mq(m);
    for(auto &c:mq)cin>>c;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    vector<Punto> points(n);
    points[0] = Punto(0.0,1.0);
    double rotar = (2*PI)/n;
    for(int i = 1;i<n;i++){
        points[i] = points[i-1].RotarCCW(rotar);
    }
    // for(int i = 0;i<n;i++)cout<<points[i].x<<" "<<points[i].y<<endl;
    double matrix[m][n];
    for(int i = 0;i<n;i++)nums[i] == mq[0]?matrix[0][i] = 1:matrix[0][i] = inf;
    for(int i = 1;i<m;i++){
        for(int j = 0;j<n;j++){
            matrix[i][j] = inf;
        }
    }
    for(int i = 1;i<m;i++){
        for(int j = 0;j<n;j++){
            if(nums[j] == mq[i]){
                for(int k = 0;k<n;k++){
                    if(matrix[i-1][k]!= inf){
                        if(isless(points[j].Dist(points[k])+matrix[i-1][k],matrix[i][j]))matrix[i][j] = matrix[i-1][k]+points[j].Dist(points[k]);
                        // matrix[i][j] = min(matrix[i][j],points[j].Dist(points[k]));
                    }
                }
            }
            else matrix[i][j] = inf;
        }
    }

    double ans = inf;
    for(int i = 0;i<n;i++)ans = min(matrix[m-1][i],ans);
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
}