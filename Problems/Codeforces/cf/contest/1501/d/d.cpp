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

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return -1;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return -1;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return -1;
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
        return -1;  
    return lx;
}

int solve(vector<int> a,vector<int> b,int k){
    int n = a.size();
    int m = b.size();
    int repm = ((n*m)/__gcd(n,m))/m;
    int repn = ((n*m)/__gcd(n,m))/n;
    vector<int> ms(repm);
    vector<int> pos(3*max(n,m)+1,-1);
    for(int i = 0;i<n;i++)
        pos[a[i]] = i;
    for(int i = 0;i<m;i++){
        if(pos[b[i]]==-1)continue;
        int x = find_all_solutions(m,-n,pos[b[i]]-i,0,repm-1,0,repn-1);
        if(x ==-1)continue;  
        ms[x]++;
    }
    for(auto &c:ms)c = m-c;
    int ciclo = 0;
    int i;
    for(i = 0;i<repm;i++){
        ciclo+= ms[i];
        if(ciclo>=k)break;
    }
    if(ciclo>=k){
        int base = m*i;
        int start = (m*i)%n;  
        int bads = ciclo-ms[i];
        for(int i = 0;i<m;i++){
            if(a[(start+i)%n]!= b[i])bads++;
            base++; 
            if(bads==k)break;          
        }
        return base;
    }
    else {
        int base = (n*m)/__gcd(n,m);
        int z = k/ciclo;
        base*=z;
        k-=ciclo*z;
        if(k==0){
            k+=ciclo;
            base-=(n*m)/__gcd(n,m);
        }
        int i;
        int sum = 0;
        for(i = 0;i<repm;i++){
            sum+= ms[i];
            if(sum>=k)break;
        }
        base = base+(m*i);
        int start = (m*i)%n;
        int bads = sum-ms[i];
        for(int i = 0;i<m;i++){
            if(bads==k)break;          
            if(a[(start+i)%n]!= b[i])bads++;
            base++; 
        }
        return base;
    }
}

signed main(){__
	int t= 1,n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    if(m>n)cout<<solve(b,a,k)<<endl;
    else cout<<solve(a,b,k)<<endl;
    return 0;
}  
