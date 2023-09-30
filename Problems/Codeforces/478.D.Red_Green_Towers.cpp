#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gauss(lli n){
    return (n*(n+1))/2;
}
int solve(int n,int r,int g){
    if(r<0)return 0;
    if(g<0)return 0;
    if(n == 0)return 1;
    if(r == 0)
        return g>=gauss(n);
    if(g == 0)
        return r>=gauss(n);
    return solve(n-1,r-n,g)+solve(n-1,r,g-n);
}
int main(){
    lli r,g;
    cin>>r>>g;
    lli n;
    int lo = 1,hi = 1000000;
    while(lo<hi){
        int m = (lo+hi+1)>>1;
        if(gauss(m)<= r+g)
            lo = m;
        else hi = m-1;
    } 
    n = hi;
    cout<<solve(n,r,g)<<endl;
    return 0;
}