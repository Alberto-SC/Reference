#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,x,y;
    cin>>T;
    while(T--){
        cin>>n>>m>>x>>y;
        int l = 0,r = 1e12;
        int lcm = x*y/__gcd(x,y);
        while(l+1<r){
            int N = (l+r)>>1;
            
            int A = N-(N/x);
            int B = N-(N/y);
            int C = N-((N/x)+(N/y))+ (N/lcm);
            A-=C;
            B-=C;
            if(max(0ll,n-A) + max(0ll,m-B)<=C)r = N;
            else l = N;
        }
        cout<<r<<endl;
    }
    return 0;
}