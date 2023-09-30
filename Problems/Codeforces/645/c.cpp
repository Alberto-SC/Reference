#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,x1,y1,x2,y2;
    cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        if(x1 == x2 || y1 == y2)cout<<1<<endl;
        else {
            lli fi = x2-x1;
            lli se = y2-y1;
            cout<<(fi*se)+1<<endl;
        }
    }
    return 0;
}