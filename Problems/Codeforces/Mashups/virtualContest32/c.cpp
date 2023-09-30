#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    // for(int i = 2;i<32;i++){
    //     int mx = -1;
    //     for(int j = 1;j<i;j++){
    //         if(__gcd(i^j,i&j)>mx){
    //             mx = __gcd(i^j,i&j);
    //         }
    //     }
    //     for(int j = 1;j<i;j++){
    //         if(__gcd(i^j,i&j)==mx){
    //             bitset<10> a(i);
    //             bitset<10> b(j);
    //             cout<<i<<" "<<j<<" "<<mx<<endl;
    //             cout<<a<<" "<<b<<endl;
    //         }
    //     }
    // }
    while(t--){
        cin>>n;
        bool flag = false;
        int p2 = 0;
        for(int i = 0;i<30;i++){
            if(n ==(1<<i)-1){
                flag = true;
                break;
            }
            if(n<(1<<i)){
                p2 = (1<<i);
                break;
            }
        }
        if(flag){
            int ans = 1;
            for(int i = 2;i*i<=n;i++){
                if(n %(n/i) ==0){ans = n/i;break;}
            }
            cout<<ans<<endl;
        }
        else{
            int ans = ~n;
            p2--;
            ans&=p2;
            cout<<__gcd(n^ans,n&ans)<<endl;
        }

    }
    return 0;
}  


