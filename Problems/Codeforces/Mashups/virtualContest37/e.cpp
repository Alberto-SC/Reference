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
int find_any_solution(int a, int b, int c, int &x0, int &y0) {
    int g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

signed main(){__
	int t= 1,n,a,b,c;
    while(t--){
        cin>>a>>b>>c;
        int x,y;

        if(a ==0){
            if(c%b)
                cout<<-1<<endl;
            else 
                cout<<0<<" "<<-(c/b)<<endl;
            
        }
        else if(b== 0){
            if(c%a)
                cout<<-1<<endl;
            else 
                cout<<-(c/a)<<" "<<0<<endl;
        }
        else{
            if(find_any_solution(a,b,-c,x,y))
                cout<<x<<" "<<y<<endl;
            else    
                cout<<-1<<endl;
        }
    }
    return 0;
}  
