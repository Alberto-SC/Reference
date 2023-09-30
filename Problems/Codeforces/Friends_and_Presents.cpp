#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,m,x,y;
lli lcm;
bool check(lli z){
    lli size1, size2,size3;
    size1 = z/y;
    size2 = z/x;
    size3 = z-(size2+size1)+(z/lcm);
    size1-= z/lcm;
    size2-= z/lcm;
    lli a = n,b = m;
    a-=size1;
    b-=size2;
    a<0?a=0:a=a;
    b<0?b=0:b=b;
    return(a+b<=size3);
}

int main(){
    cin>>n>>m>>x>>y;
    lcm =y*x;
    lli l = 1,r = 2000000007;
    while(l+1<r){
        lli m = (l+r+1)>>1;
        if(check(m))
            r = m;
        else 
            l = m; 
    }
    cout<<r<<endl;
    return 0;
}