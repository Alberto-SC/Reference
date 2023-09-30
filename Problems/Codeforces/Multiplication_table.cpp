#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int N = 1e6+6;
ll f(ll x, int n, int m){
    ll res = 0;
    --x;
    for(int i=1;i<=n;++i) 
    	res+=min((ll)m, x/i);
    cout<<res<<endl;
    return res;
}

int main(){   
    int n, m;
    ll k;
    cin>>n>>m>>k;  
    ll l = 1, r = 1ll*n*m+1;
    while(l<r){
        ll x = (l+r)>>1;
        if(f(x,n,m)<k) l = x+1; 
        else r = x;
    }
    cout<<l-1<<endl;
    
    return 0;
}