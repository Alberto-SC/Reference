#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &c:a)cin>>c;
    sort(a.rbegin(),a.rend());
    double ans = 0;
    for(int i = 0;i<n;i++){
        if(i&1) ans-= a[i]*a[i]*PI;
        else ans+= a[i]*a[i]*PI;
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    return 0;
}