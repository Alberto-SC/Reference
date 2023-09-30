#include <bits/stdc++.h>
using namespace std;
const double PI = M_PI;
const double EPS = 1e-8;
 
double ang[123456];
 
int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin>>x>>y;
        ang[i] = atan2(y, x);
        if (ang[i] < -EPS) {
            ang[i] += 2 * PI;
        }
    }
    sort(ang, ang + n);
    double ans = ang[n - 1] - ang[0];
    for (int i = 0; i < n; i++) {
        cout<<ang[i]<<" ";
        // cout<<ang[i]*180/PI<<" ";
        // double cur = 2 * PI - (ang[i + 1] - ang[i]);
        // if (cur < ans) ans = cur;
    }
    printf("%.17lf\n", ans / PI * 180);
}