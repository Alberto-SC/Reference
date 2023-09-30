#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){

        vector<int> a(4);
        for(auto &c:a)cin>>c;
        int x = 0,y =0;

        int ans = a[0];
        x+=a[0],y+=a[0];

        while(a[1] || a[2] ||a[3]){
            if(y && a[1]){
                
            }
        }
        if(x ==0 && y == 0){
            cout<<1<<endl;
            continue;
        }
        
        if(a[2]>a[1]){
            a[2]-=x; 
            y+=x;
            x = 0;


            int mn = min(a[2]/y,a[1]/y);

            ans+=y*mn*2
    
        }
        else{
            a[1]-=x;
            x+=y;
            y = 0;
        }

        ans+=min({x+1,y+1,a[3]});
        cout<<ans<<endl;

    }
    return 0;
}