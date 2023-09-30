#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

// Definiciones iniciales.
typedef long double Double;
typedef long long Long;
typedef pair<int, int> pii;

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



// Test de mano derecha: CCW = 1, CW = -1, Colineal = 0.
int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
  Double ccw = (p-o).Cruz(q-o);
  return EQ(ccw, 0)? 0: (ccw < 0)? -1: 1;
}
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

// Saber si un punto p esta en la recta r.
bool PuntoEnRecta(const Punto& p, const Linea& r){
  return !ManoDerecha( r.p, r.q, p );
}
// Saber si un punto p esta en el segmento s.
bool PuntoEnSegmento(const Punto& p, const Linea& s) {
  return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}

// Saber si dos lineas l y m son paralelas.
bool LineasParalelas(const Linea& l, const Linea& m) {
  return EQ( 0, ( l.q - l.p ).Cruz( m.q - m.p ) );
}

// Saber si dos lineas l y m son iguales.
bool LineasIguales(const Linea& l, const Linea& m) {
  return LineasParalelas(l, m)
    && EQ( 0, ( l.p - l.q ).Cruz( l.p - m.q ) )
    && EQ( 0, ( m.q - m.p ).Cruz( m.q - l.p ) );
}

// Saber si dos lineas l y m son perpendiculares.
bool LineasPerpendiculares(const Linea& l, const Linea& m) {
  return EQ( 0, ( l.q - l.p ).Dot( m.q - m.p ) );
}

// Obtener una linea paralela a l que pase por p.
Linea ParalelaEnPunto(const Linea& l, const Punto& p) {
  return Linea(p, p + ( l.q - l.p ));
}

// Obtener una linea perpendicular a l que pase por p.
Linea PerpendicularEnPunto(const Linea& l, const Punto& p) {
  return Linea(p, p + ( l.q - l.p ).rot90());
}

// Saber si dos rectas r y s se intersectan.
// No intersectan = 0, Interseccion en un punto = 1,
// Interseccion paralela en infinitos puntos = -1.
int InterseccionRectas(const Linea& r, const Linea& s) {
  if (LineasIguales(r, s)) return -1;
  return LineasParalelas(r, s)? 0: 1;
}

// Saber si una recta r y un segmento s se intersectan.
// No intersectan = 0, Interseccion en un punto = 1,
// Interseccion paralela en infinitos puntos = -1.
int IntersecRectaSegmen(const Linea& r, const Linea& s) {
  if (LineasIguales(r, s)) return -1;
  if (LineasParalelas(r, s)) return 0;
  int t1 = ManoDerecha(r.p, r.q, s.p);
  int t2 = ManoDerecha(r.p, r.q, s.q);
  return (t1 != t2)? 1: 0;
}

// Saber si dos segmentos s y t se intersectan.
// No intersectan = 0, Interseccion en un punto = 1,
// Interseccion paralela en infinitos puntos = -1.
int InterseccionSegmentos(const Linea& s, const Linea& t) {
  //cout<<"Puntos linea :"<<s.p.x<<","<<s.p.y<<"   "<<s.q.x<<","<<s.q.y<<"   Puntos rectangulo :"<<t.p.x<<","<<t.p.y<<"   "<<t.q.x<<","<<t.q.y<<endl;
  int t1 = ManoDerecha(s.p, s.q, t.p);
  int t2 = ManoDerecha(s.p, s.q, t.q);

  if (t1 == t2) return t1? 0:
    (PuntoEnSegmento(s.p, t) ||
     PuntoEnSegmento(s.q, t) ||
     PuntoEnSegmento(t.p, s) ||
     PuntoEnSegmento(t.q, s))? -1: 0;

  return (ManoDerecha(t.p, t.q, s.p) !=
      ManoDerecha(t.p, t.q, s.q))? 1: 0;
}

// Obtener punto de interseccion entre lineas l y m.
Punto PuntoInterseccion(const Linea& l, const Linea& m) {
  Punto a = l.p, b = l.q, c = m.p, d = m.q;
  b = b-a; d = c-d; c =c-a;
  assert( !LineasParalelas( l, m ) );
  return a + b*(c.Cruz( d )/b.Cruz( d ));
}

int main(){
  int n,x,y;
  cin>>n;
  vector<Punto> p[n];
  for(int i = 0;i<n;i++){
    for(int j = 0;j<4;j++){
      cin>>x>>y;
      p[i].push_back(Punto(x,y));
    }
    int in1,in2,in3,in4;
    in1 = InterseccionSegmentos(Linea(p[i][0],p[i][1]),Linea (p[i][2], Punto(p[i][3].x- (p[i][3].x-p[i][2].x) , p[i][3].y)));
    in2 = InterseccionSegmentos(Linea(p[i][0],p[i][1]),Linea (p[i][2], Punto(p[i][3].x,  p[i][3].y+ (p[i][2].y-p[i][3].y)  )));
    in3 = InterseccionSegmentos(Linea(p[i][0],p[i][1]),Linea (p[i][3], Punto(p[i][3].x , p[i][2].y)));
    in4 = InterseccionSegmentos(Linea(p[i][0],p[i][1]),Linea (p[i][3], Punto(p[i][2].x,  p[i][3].y)));
    if(in1 == 1 || in2 ==1|| in3 ==1 ||in4 == 1||in1 == -1||in2 == -1|| in3 == -1||in4 == -1){
      cout<<"T"<<endl;
    } 
    /*else if(    ((p[i][0].x > p[i][2].x)&&(p[i][0].x < p[i][3].x))   &&   ((p[i][0].y < p[i][2].y)&&(p[i][0].y > p[i][3].y))  
    		&& ((p[i][1].x > p[i][2].x)&&(p[i][1].x < p[i][3].x))   &&   ((p[i][1].y < p[i][2].y)&&(p[i][1].y > p[i][3].y)) )	
    	cout<<"T"<<endl;
    */
    else cout<<"F"<<endl;
  }

  return 0;
}




#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/**
    Using cross products would be much simplier to solve this problem. In this solution,
    I practiced geometry basics without cross products.
    There is a bug in UVA's official answer (http://www.uvatoolkit.com/problemssolve.php).
    This case should output "T" (since the line segment intersects with the rectangle at (-1, -3))
    , but the official answer output "F":
    2 -5 -10 3 -1 0 2 -3
*/

static const double EPS = 1e-9;

/** Model a point. */
struct Point { double x, y; };

/** Model a linear equation ax + by + c = 0. 
    a is the slope. 
    b = 0 if it is a vertical line; otherwise b = 1.
*/
struct Line { double a, b, c; };

/** Given p1 and p2, compute the linear equation and store it in l. */ 
void pointsToLine(Point p1, Point p2, Line &l) 
{
    // l is a vertial line.
    if (p1.x == p2.x)
    {
        l.a = 1.0;
        l.b = 0;
        l.c = -p1.x;
    }
    else 
    {
        l.a = -(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a * p1.x) - p1.y;
    }
}

bool areSame(Line l1, Line l2)
{
    return (fabs(l1.a - l2.a) < EPS 
            && fabs(l1.b - l2.b) < EPS
            && fabs(l1.c - l2.c) < EPS);
}

/** If l1 and l2 are not parallel, return true and store their intersected 
    point in p; otherwise return false. */
bool areIntersected(Line l1, Line l2, Point &p) {

    // If l1 and l2 are parallel, return false.
    if (fabs(l1.a - l2.a) < EPS 
        && fabs(l1.b - l2.b) < EPS)
        return false;

    // Solve the system of two linear algebraic equations.
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);

    return true;
}

/** Return the Euclidean distance between p1 and p2. */
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) 
                 + (p1.y - p2.y) * (p1.y - p2.y));
}

/** Given p1, p2 and p3 are collinear, is p3 on the segment formed between p1 and p2? */
bool isOnSegment(Point p1, Point p2, Point p3)
{
    if (dist(p1, p3) - EPS <= dist(p1, p2)
        && dist(p2, p3) - EPS <= dist(p1, p2))
        return true;

    return false;
}

/** Is p3 inside the rectangle formed by left-top p1 and right-bottom p2? */
bool isInsideRectangle(Point p1, Point p2, Point p3)
{
    if (p3.x <= max(p1.x, p2.x)
        && p3.x >= min(p1.x, p2.x)
        && p3.y <= max(p1.y, p2.y)
        && p3.y >= min(p1.y, p2.y))
        return true;

    return false;
}

int main()
{    
    int n;
    cin >> n;

    while ( n-- )
    {
        Point line[2];
        Point rectangle[4];

        cin >> line[0].x >> line[0].y 
            >> line[1].x >> line[1].y;
        cin >> rectangle[0].x >> rectangle[0].y 
            >> rectangle[2].x >> rectangle[2].y;

        // Is line[0] or line[1] inside the rectangle?
        if (isInsideRectangle(rectangle[0], rectangle[2], line[0])
            || isInsideRectangle(rectangle[0], rectangle[2], line[1]))
        {
            cout << "T" << endl;
            continue;
        }
        
        // Now check intersections.
        rectangle[1] = rectangle[0];
        rectangle[3] = rectangle[2];
        swap(rectangle[1].y, rectangle[3].y);

        Line lineSegment;
        pointsToLine(line[0], line[1], lineSegment);
        bool intersect = false;
        // Loop over every edge of the rectangle.
        for (int i = 0; i < 4; ++i) 
        {
            // Compute the equation of this edge.
            Line rectangleEdge;
            pointsToLine(rectangle[i], rectangle[(i + 1) % 4], rectangleEdge);

            // If the equations are the same, check if the two segments overlap.
            if (areSame(lineSegment, rectangleEdge))
            {
                if (isOnSegment(line[0], line[1], rectangle[i])
                    || isOnSegment(line[0], line[1], rectangle[(i + 1) % 4]))
                {
                    intersect = true;
                    break;
                }
                continue;
            }

            // Otherwise, check if they intersect and the intersection is inside both segments.
            Point p;
            if (areIntersected(lineSegment, rectangleEdge, p)) 
            {
                if (isOnSegment(line[0], line[1], p)
                    && isOnSegment(rectangle[i], rectangle[(i + 1) % 4], p))
                {
                    intersect = true;
                    break;
                }
            }
        }

        if (intersect)
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
    return 0;
}