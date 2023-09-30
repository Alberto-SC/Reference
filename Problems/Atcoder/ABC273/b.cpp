#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k,x;
    int z = 0;

    for(int i = 0;i<n;i++ ){
        z+=i;
    }
    std::cout << z << endl;

    while(T--){
        cin>>x>>k;
        int pow10=1;
        for(int i=0;i<k;i++){
            x/=pow10;
            int m=(x%10);
            if(m<=4)x-=m;
            else x+=(10-m);
            x*=pow10;
            pow10*=10;
        }
        cout<<x<<endl;
    }
    return 0;
}
