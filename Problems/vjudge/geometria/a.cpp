#include <bits/stdc++.h>
using namespace std;
int main(){
    double a,b,x,y,v;
    int n;
    cin>>a>>b;
    cin>>n;
    cout<<fixed<<setprecision(10);
    double mn = 10000;
    for(int i = 0;i<n;i++){
        cin>>x>>y>>v;
        double distance;
        distance = (x-a)*(x-a);
        distance+=(y-b)*(y-b);
        distance = sqrt(distance);
        double time = distance/v;
        if(islessequal(time,mn))mn = time;
    }
    cout<<mn<<endl;
    return 0;
}