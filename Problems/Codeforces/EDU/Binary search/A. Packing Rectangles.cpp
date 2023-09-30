#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli w,h,n;


bool check(lli x){
    lli v = x/h;
    lli h = x/w;
    if(v>=n || h>=n ||v*h>=n)return true;
    return false;
}
int main(){
    cin>>w>>h>>n;
    lli l = max(w,h)-1,r = 1e18;
    
    while(l+1<r){
        lli mid = (l+r)>>1;
        if(check(mid))
            r = mid;
        else 
            l = mid;
    }
    0 0 0 0 1 1 1 1 1 1
            ^
    cout<<r<<endl;
    return 0;
}