#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long  
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int gcd(int a, int b, int &s, int &t){
    int s0=1, s1=0;
    int t0=0, t1=1;
    while (b != 0) {
        int q = a/b;
        int tmp = a%b;
        a = b;
        b = tmp;
        tmp = s0 - q*s1;
        s0 = s1;
        s1 = tmp;
        tmp = t0 - q*t1;
        t0 = t1;
        t1 = tmp;
    }
    s = s0;
    t = t0;
    return a;
}

void solve(vector<int>a, vector<int> m, int n, int &x, int &mod){
    int s, t;
    int a1 = a[0];
    int m1 = m[0];
    for ( int i = 1; i < n; i++ ) {
        int a2 = a[i];
        int m2 = m[i];
        int g =gcd(m1, m2, s, t);
        if ( a1 % g != a2 % g ) {
            x = mod = -1;
            return;
        }
        gcd(m1/g, m2/g, s, t);
        mod = m1 / g * m2;
        int x = (a1*(m2/g)*t + a2*(m1/g)*s) % mod;
        a1 = x;
        if (a1 < 0) a1 += mod;
        m1 = mod;
    }
    x = a1;
}

vector<int>  Get_t(int x, int y){
    int mx = (x + y - sqrt(x*x+y*y-x*y))/6.0;
    vector<int> m;
    for(int i = mx-2;i<=mx+2;i++) {
        int v = ((4*i - 2*(x+y))*i+x*y)*i;
        m.push_back(v);
    }
    sort(m.rbegin(),m.rend());
    m.resize(3);
    return m;
}


signed main(){__
	int t= 1,a,b,c,d,e,f,g;
    vector<int> as(3);
    while(t--){
        cin>>a>>b>>as[0]>>as[1]>>as[2]>>f>>g;
        vector<int> sz = Get_t(a,b);
        int ans,mod;
        solve(as,sz,3,ans,mod);
        while(ans<f)
            ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}  

