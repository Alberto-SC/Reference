#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    double y;
    cin>>x>>y;
    cout << fixed << setprecision(2);
    if(x%5==0 && x<int(y))cout<<y-x-0.5;
    else cout<<y;
    return 0;
}