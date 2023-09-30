#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point{
    ll x , y;
    point():x(0.0),y(0.0){};
    point(ll _x , ll _y)
    {
        x = _x;
        y = _y;
    }
    ll cruz(point &p)
    {
        return x*p.y-p.x*y;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll area = 0;
    cin >> n;
    vector<point> v(n,point());
    for(int i = 0 ; i < n ; i++)
        cin >> v[i].x >> v[i].y;
    for(int i = 0 ; i < n ; i++)
        area += v[i].cruz(v[(i+1)%n]);
    ll pointsBorder =n;
    for(int i =0;i<n;i++)
        pointsBorder+= __gcd( llabs(v[i].x - v[(i+1)%n].x ) , llabs( v[i].y - v[(i+1)%n].y) )-1;
        // cout << (int)fabs(round(v[i].x - v[(i+1)%n].x )) << " , " <<  (int)fabs(round( v[i].y - v[(i+1)%n].y )) << '\n';
    
    // cout << area/2 << " " << pointsBorder << '\n';
    cout<<(area/2)-(pointsBorder/2)+1<<endl;
    return 0;
}