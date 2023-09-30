#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point
{
    double x , y;
    point(double _x , double _y):x(_x,y(_y)){};
    double cruz(point &p)
    {
        return self.x*p.y-p.x*self.x;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    double area = 0 , per = 0;
    cin >> n;
    vector<point> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i].x >> v[i].y;
    for(int i = 0 ; i < n ; i++)
    {
        area += v[i].cruz(v[(i+1)%n]);
    }
    cout << area << '\n';
    return 0;
}