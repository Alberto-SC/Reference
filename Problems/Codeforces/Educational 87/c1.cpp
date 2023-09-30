#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(){
    int t,n;
    cin>>t;
    cout<<fixed<<setprecision(10);
    while(t--){
        cin>>n;
        double x = 1/tan(PI/(2.0*n));
        cout<<x<<endl;
    }
    
    return 0;
}