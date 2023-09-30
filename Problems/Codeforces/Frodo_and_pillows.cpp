#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,m,k;
bool check(lli x){
    lli z = 0,y = 0;
    int d = k-1;
    int d2 = n-k;
    if(d>x-1){
        z = ((x-1)*x)/2;
        z+=d-(x-1);
    }
    else 
        z= (d*(x-1+x-d))/2;
    
    if(d2>x-1){
        y = ((x-1)*x)/2;
        y+=d2-(x-1);
    }  
    else 
        y = (d2*(x-1+x-d2))/2;

    if(x+z+y<=m)return true;
    else return false;
}
int main(){
    cin>>n>>m>>k;
    lli l = 1,r = m+1;
    while(l<r){
        lli mid = (l+r)>>1;
        if(check(mid))
            l = mid+1;
        else r = mid;
    }
    cout<<l-1<<endl;
    return 0;
}   