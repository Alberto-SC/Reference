#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,a,b,c,d,x,y,x1,x2,y1,y2;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        x+=-a+b, y+=-c+d;
        if (x>=x1 && x<=x2 && y>=y1 && y<=y2 && (x2>x1||a+b==0)&&(y2>y1||c+d==0))
            cout<<"Yes"<<endl;
        
        else
            cout<<"No"<<endl;
        
    }
    
    return 0;
}