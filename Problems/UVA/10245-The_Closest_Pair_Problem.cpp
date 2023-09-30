#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;
struct Point {                                                              
    double x, y;                                                            
};
double MlineClosest( Point line[], int size, double d){           //Esta funcion calcula la distancia minima entre puntos que esten dentro de lacircunferencia de radio d
    sort(line, line + size,[](const Point& P1, const Point& P2) { //Ordenamos segun x                             
            return P1.y < P2.y;                                         
        }
    );
    double min = d;                                               //variables para la distancia y el minimo
    for (int i = 0; i<size; ++i){
        for (int j = i+1; j < size && (line[j].y - line[i].y) < min; ++j){   //Fuerca bruta
                double dist = sqrt((line[i].x-line[j].x)*(line[i].x-line[j].x)+
                              (line[i].y -line[j].y) *(line[i].y -line[j].y));
            if (dist < min)
                min = dist;         //Si la distancia calculada es menor a la almacenada, actualizamos
        }
    }
    return min;
}
double Cumulo(Point Px[],int n ){
    if(n <= 3){                         //Caso base resuelto con fuersa bruta
        double min = 9999999;
        for(int i = 0;i<n;i++){ 
            for(int j = i+1;j<n;j++){   //Para cada punto i calcular la distancia con todos los demas puntos 
                double dist = sqrt(((Px[i].x-Px[j].x)*(Px[i].x-Px[j].x))+
                              ((Px[i].y -Px[j].y)*(Px[i].y -Px[j].y)));
                if (dist < min) 
                    min = dist;         //Si la distancia calculada es menor a la ya almacenada actualizamos min
            }
        }
        return  min;
    }
    int m = n/2;                        //Encontramos el punto medio para dividir el arreglo
    double dl = Cumulo(Px, m);          //Encontramos recursivamente la distancia minima del lado izquierdo
    double dr = Cumulo(Px+m,n-m);       //Encontramos recursivamente la distancia minima del lado derecho
    double d = min(dl, dr);                     //Obtenemos el minimo de las dos distancias
    Point line[n];                      //Arreglo para almacenar los valores cercanos a la linea vertical que representa la mitad del arreglo de puntos
    int j = 0;                          
    for (int i = 0; i < n; i++)         
        if (abs(Px[i].x - Px[m].x) < d) //Para cada punto checamos que este dentro de un radio menor a la distancia menor entre el lado izquierdo y derecho
            line[j++]= Px[i];           //Almacenamos los puntos que cumplen la condición 
    
    return min(d, MlineClosest(line, j,d) );      //Funcion para calcular la minima distancia del arreglo line
}
int main(){ 
    cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0);       //Sentencias para hacer la entrada y salida cin/cout mas rapida desvinculandolo de stdio
    int n;                              //Variable para el numero de puntos                         
    cin>>n;
    while(n){
        Point s[n];                         //Arreglo de puntos x,y
        for(int i = 0;i<n;i++){             //Lectura y almacenamiento de los datos
            cin>>s[i].x>>s[i].y;
        }                                  
        sort(s,s +n,[](const Point& P1,const Point& P2){
            return P1.x < P2.x;
        });                                 //Ordenamos segun x
        cout.setf(ios::fixed,ios::floatfield);      
        cout.precision(4); 
        double res = Cumulo(s,n);      
        if(res <10000)
            cout<<res<<endl;
        else 
            cout<<"INFINITY"<<endl;

        cin>>n;
    }
    return 0;
}
