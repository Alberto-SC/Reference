#include <bits/stdc++.h>
using namespace std;
typedef double dato;

dato dist(dato px1, dato py1, dato px2, dato py2){
    dato dx = (px1-px2) * (px1-px2);
    dato dy = (py1-py2) * (py1-py2);
    return sqrt(dx+dy);
}
int main (){
    int n; cin >> n;
    while(n--){
        dato fx1, fy1, fx2, fy2, d;
        cin>>fx1>>fy1>>fx2>>fy2>>d;
        dato a, b, x0, y0;
        x0 = (fx1+fx2) / 2.0;
        y0 = (fy1+fy2) / 2.0;
        a = d/2.0;
        dato a2 = a*a;
        b = sqrt( ( a2 - pow(dist(x0, y0, fx1, fy1), 2) ) );
        dato b2 = b*b;
        if(fy1 == fy2){
            int cont = 0;
            for(int x = -400; x <= 400; x++){
                for(int y = -400; y <= 400; y++){
                    dato res = ( (pow(x-x0,2))/a2 ) + ( (pow(y-y0,2))/b2 );
                    if(res < 1){
                        //cout << x << ", " << y << ": " << res << endl;
                        cont++;
                    }

                }
            }
            cout << cont << "\n";

        } else if(fx1 == fx2){
            int cont = 0;
            for(int x = -400; x <= 400; x++){
                for(int y = -400; y <= 400; y++){
                    dato res = ( (pow(x-x0,2))/b2 ) + ( (pow(y-y0,2))/a2 );
                    if(res < 1){
                        //cout << x << ", " << y << ": " << res << endl;
                        cont++;
                    }
                }
            }
            cout << cont << "\n";
        } else {
            int cont = 0;
            for(int x = -4; x <= 4; x++){
                for(int y = -4; y <= 4; y++){
                    dato f1 = dist(x, y, fx1, fy1);
                    dato f2 = dist(x, y, fx2, fy2);
                    //cout << f1 << " + " << f2 << endl;
                    //cout << x << ", " << y << ": " << f1+f2 << endl;
                    if(f1 + f2 < d){
                        cont++;
                    }
                }
            }
            cout << cont << "\n";
        }
    }

    return 0;
}