#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double

bool check(int x,int y,int a,int b,int n){
    // cout<<"N: "<<n<<endl;
    ld L1 = (x-(n*b))/((a-b)*1.0);
    int R1 = n;
    int L2 = 0;
    ld R2 = (y-(n*a))/((b-a)*1.0);
    if((int)floor(R2)<0|| (int)ceil(L1)>n)return false;
    // cout<<L1<<" "<<R1<<" "<<L2<<" "<<R2<<endl;
    L1 = max((int)ceil(L1),L2);
    R1 = min(R1,(int)floor(R2));
    if(L1>R1)return false;
    return true;
    // for(int p= 0;p<=n;p++){
    //     int q = n-p;
    //     int r1 = p*a + q*b;
    //     int r2 = q*a + p*b;
    //     // if(r1<=x && r2<=y)return true;
    //     cout<<p<<" "<<r1<<" "<<r2<<endl;
    // }
    // cout<<endl;
    // return false;
}

signed main(){__
    int T = 1,n,x,y,a,b;
    cin>>T;
    while(T--){
        cin>>x>>y>>a>>b;
        if(a>b)swap(a,b);
        int l = 0,r = 2e9;
        if(b==a){
            int ans = min(x/a,y/a);
            cout<<ans<<endl;
            continue;
        }
        while(l+1<r){
            int m= (l+r)>>1;
            if(check(x,y,a,b,m))l = m;
            else r = m;
        } 
        cout<<l<<endl;
        // cout<<check(x,y,a,b,50)<<endl;
    }
    return 0;
}