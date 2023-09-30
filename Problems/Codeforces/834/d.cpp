#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int x = n;
        int ans = 1;
        int p2 = 0,p2m = 0;
        int p5 = 0,p5m = 0;
        while(x%2==0){
            x/=2;
            p2++;
        }
        while(x%5==0){
            x/=5;
            p5++;
        }
        while(p2<p5){
            if(ans*2<=m){
                ans*=2;
                p2++;
            }
            else break;
        }
        while(p5<p2){
            if(ans*5<=m){
                ans*=5;
                p5++;
            }
            else break;
        }
        while(1){
            if(ans*10<=m){
                p2++;
                p5++;
                ans*=10;
            }
            else break;
        }
        int k = m/ans;
        cout<<ans*k*n<<endl;
    }
    return 0;
}