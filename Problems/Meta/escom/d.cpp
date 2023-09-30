#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


long double area(int x1, int y1, int x2, int y2, int x3, int y3){
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
  
signed main(){__
	int t= 1,n,Ax,Ay,Bx,By,Cx,Cy,x,y;
    cin>>t;
    int test = 1;
    while(t--){
        cin>>x>>y;
        cin>>Ax>>Ay;
        cin>>Bx>>By;
        cin>>Cx>>Cy;
        long double A1,A2,A3,A4;
        A1 = area(Ax,Ay,Bx,By,Cx,Cy);
        A2 = area(x,y,Bx,By,Cx,Cy);
        A3 = area(x,y,Ax,Ay,Cx,Cy);
        A4 = area(x,y,Ax,Ay,Bx,By);
        // cout<<A1<<" "<<A2<<" "<<A3<<" "<<A4<<endl;
        if(A1 == A2+A3+A4)
            cout<<"Case #"<<test<<": IN"<<endl;
        else 
            cout<<"Case #"<<test<<": OUT"<<endl;
        test++;
    }
    return 0;
}  
