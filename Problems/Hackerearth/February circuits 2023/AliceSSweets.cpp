#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
    
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        for(auto &c:c)cin>>c;


        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());

        int ans = 1e18;
        for(int i = 0;i<n;i++){
            int nxtb = lower_bound(b.begin(),b.end(),a[i])-b.begin();
            int lastc = lower_bound(c.begin(),c.end(),a[i])-c.begin();

            bool flag = true;
            if(nxtb == n )flag = false;
            if(lastc == 0 && c[lastc]>a[i])flag = false;
            if(lastc == n || c[lastc]>a[i])lastc--;
            
            if(flag){
                ans = min(ans,(b[nxtb]-a[i])+(b[nxtb]-c[lastc])+(a[i]-c[lastc]));
            }

            flag = true;
    
            int nxtc = lower_bound(c.begin(),c.end(),a[i])-c.begin();
            int lastb = lower_bound(b.begin(),b.end(),a[i])-b.begin();


            if(nxtc == n)flag = false;
            if(lastb ==0 && b[lastb]>a[i])flag = false;
            if(lastb == n || b[lastb]>a[i])lastb--;
            if(flag){
                ans = min(ans,(c[nxtc]-a[i])+(c[nxtc]-b[lastb])+(a[i]-b[lastb]));
            }
        }

        for(int i = 0;i<n;i++){
            int nxta = lower_bound(a.begin(),a.end(),b[i])-a.begin();
            int lastc = lower_bound(c.begin(),c.end(),b[i])-c.begin();

            bool flag = true;
            if(nxta == n)flag = false;
            if(lastc == 0 && c[lastc]>b[i])flag = false;
            if(lastc == n || c[lastc]>b[i])lastc--;

            if(flag)ans = min(ans,(a[nxta]-b[i])+(a[nxta]-c[lastc])+(b[i]-c[lastc]));

            flag = true;
    
            int nxtc = lower_bound(c.begin(),c.end(),b[i])-c.begin();
            int lasta = lower_bound(a.begin(),a.end(),b[i])-a.begin();

            if(nxtc == n)flag = false;
            if(lasta == 0 && a[lasta]>b[i])flag = false;
            if(lasta == n || a[lasta]>b[i])lasta--;

            if(flag)ans = min(ans,(c[nxtc]-b[i])+(c[nxtc]-a[lasta])+(b[i]-a[lasta]));
        }

        
        for(int i = 0;i<n;i++){
            int nxta = lower_bound(a.begin(),a.end(),c[i])-a.begin();
            int lastb = lower_bound(b.begin(),b.end(),c[i])-b.begin();

            bool flag = true;
            if(nxta == n)flag = false;
            if(lastb == 0 && b[lastb]>c[i])flag = false;
            if(lastb == n || b[lastb]>c[i])lastb--;

            if(flag)ans = min(ans,(a[nxta]-c[i])+(a[nxta]-b[lastb])+(c[i]-b[lastb]));

            flag = true;
    
            int nxtb = lower_bound(b.begin(),b.end(),c[i])-b.begin();
            int lasta = lower_bound(a.begin(),a.end(),c[i])-a.begin();

            if(nxtb == n )flag = false;
            if(lasta == 0 && a[lasta]>c[i] && lasta == 0)flag = false;
            if(lasta == n || a[lasta]>c[i])lasta--;

            if(flag)ans = min(ans,(b[nxtb]-c[i])+(b[nxtb]-a[lasta])+(c[i]-a[lasta]));
        }



        cout<<ans<<endl;
    }
    return 0;
}
