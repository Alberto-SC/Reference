#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p;
    long double ans= 0,ml;
    vector<int> porcent;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>p;
        porcent.push_back(p);
    }
    ml = 1/(n*1.0);
    for(int i = 0;i<n;i++){
        long double per = (porcent[i]*1.0)/100;
        ans += ml*per;
    }
    ans*=100.0;
    cout << std::fixed;
    cout << std::setprecision(6);
    cout<<ans;
}