#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli N,L,H;
lli func(lli x){
    lli R;
    lli LifeRecovered = x*H;
    lli LifeLost = (N-x)*L;
    R = min(LifeRecovered,LifeLost);
    // cout<<"I: "<<x<<" "<<R<<endl;
    return R;
}
int main(){__
	int t= 1;
    cin>>t;
    while(t--){
        cin>>N>>L>>H;
        lli R = 0;
        int l = 0,r = N;
        while(l<r){
            int mid = (l+r)>>1;
            if(func(mid)>func(mid+1))
                r = mid;
            else 
                l = mid+1;
        }
        if(func(l)>func(r))cout<<l<<endl;
        else cout<<r<<endl;
    }
    return 0;
}  

