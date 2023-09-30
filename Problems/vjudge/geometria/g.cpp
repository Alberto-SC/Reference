#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    double R,r,k;
    cin>>t;
    cout<<fixed<<setprecision(10);
    while(t--){
        cin>>R>>r>>k;
        double x0,x1,y,p,h,x;
        x0 = 0.5/R;
        x1 = 0.5/r;
        y =(x1-x0)*k;
        p = (x1 - x0) * 0.5;
        x = (x1 + x0) * 0.5;
		h = sqrt(x*x+y*y);
        cout<<h<<" "<<x<<" "<<y<<"  "<<p<<endl;
        double ans = (1/(h-p)-1/(h+p))/2;
		cout<<ans<<endl;
    }
    return 0;
}