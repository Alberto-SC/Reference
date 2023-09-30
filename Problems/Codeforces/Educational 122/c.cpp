#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__    
    int t,n,hc,dc,hm,dm,k,w,a;
    cin>>t;
    while(t--){
        cin>>hc>>dc>>hm>>dm;
        cin>>k>>w>>a;

        bool flag= false;
        for(int i = 0;i<=k;i++){
            int c = dc+ (i*w);
            int d = hc+ ((k-i)*a);
            int x = d/dm;
            if(d%dm)x++;
            int res ;
            if(__builtin_smulll_overflow(c,x,&res))flag= true;
            else if(c*x>=hm)flag = true;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}