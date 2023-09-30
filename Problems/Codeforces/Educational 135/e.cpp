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


signed main(){__
    int T = 1,n,x,y,m;
    while(T--){
        cin>>n;
        vector<pair<int,int>> v(n);
        int sum = 0;
        vector<int> A;
        for(auto &[x,y]:v)cin>>x>>y,sum+=y,A.push_back(x-y);
        sort(A.rbegin(),A.rend());

        vector<int> ac(n+1);
        for(int i = 1;i<=n;i++)
            ac[i] = ac[i-1]+A[i-1];
            
        int p = max_element(ac.begin(),ac.end())-ac.begin();
       
        cin>>m;
        for(int i = 0;i<m;i++){
            cin>>x>>y;
            pair<pair<int,int>,int> z = find_all_solutions(x,y,n,0,n,0,n);
            if(z.first.first==-1)cout<<-1<<endl;
            else {
                int dist =  (p-1)-(z.first.first*x);
                int up = (z.first.second-z.first.first)/z.second;
                int mx = min(up,dist/(z.second*x)+1);
                int R1 = z.first.first*x+(mx*z.second*x);
                int R2 = R1-(z.second*x);
                int ans =0 ;
                if(R1 <= n)
                    ans = max(ans,sum+ac[R1]);
                if(R2 >= 0)
                    ans = max(ans,sum+ac[R2]);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}