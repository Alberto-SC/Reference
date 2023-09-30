#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b); 
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}


// This returns the pair {{min x, max x}, offset} or {{-1,-1},-1} if is not solution

pair<pair<int,int>,int> find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return {{-1,-1},-1};
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return {{-1,-1},-1};
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return {{-1,-1},-1};
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return {{-1,-1},-1};
    return {{lx,rx},b};
}

int lcm(int a,int b){
    return a*b/__gcd(a,b);
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        if(x== y){
            cout<<x<<endl;
            continue;
        }
        int ans = lcm(x,y)-(x+y);
        if(ans<=0)ans+=lcm(x,y);
        cout<<ans<<endl;
        // if(x<y)swap(x,y);
        // int c = (y-(x%y))-(x-y);
        // int mx = 1e18/x;
        // auto ans = find_all_solutions(x,-y,c,-1e18,mx,-1e18,1e18);
        // n = (ans.first.second*x)+(x-y);
        // cout<<n<<endl;
    }
    return 0;
}