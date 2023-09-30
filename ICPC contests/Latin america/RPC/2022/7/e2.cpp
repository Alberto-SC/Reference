#include <bits/stdc++.h>
using namespace std ;
using dt = double ;
using pt = pair<dt, dt> ;
using ll = long long ;
vector<pt> poly ;
pt door;
int n;
dt ia(pt &p, pt &v) {
   return (v.second + p.second) * (p.first - v.first) ;
}

int main() {
    cout << setprecision(15);
    cin>>n;
    poly.resize(n);
    for (auto &v : poly)
        cin >> v.first >> v.second;

    dt rarea = 0;
    door = poly[0];
    pt p = poly[n-1];

    for(auto v:poly){
        rarea += ia(door, p) + ia(p, v) + ia(v, door);
        p = v;
    }

    rarea *= 0.5;
    p = poly[n-1];
    dt area = 0;
    for (auto v : poly) {
        auto tarea = ia(door, p) + ia(p, v) + ia(v, door);
        if(area + tarea >= rarea){
            pt d = {(p.first*(tarea+area-rarea)+v.first*(rarea-area))/tarea,(p.second*(tarea+area-rarea)+v.second*(rarea-area))/tarea} ;
            cout<<d.first<<" "<<d.second<<endl;
            return 0;
        }
        area += tarea;
        p = v;
    }
    return 0;
}