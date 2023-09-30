#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n,m;
    cin>>n;
    vector<int> factoradic(10);
    vector<int> f(10);
    f[0] =1 ;
    
    if(n == 1){
        cout<<0<<endl;
        return 0;
    }

    for(int i = 1;i<=9;i++)
        f[i] = f[i-1]*i;
    
    for(int i = 9;i>=0;i--){
        factoradic[i] = n/f[i];
        n-=factoradic[i]*f[i];
    }
    
    string ans = "";
    for(int i = 1;i<=9;i++){
        for(int j = 0;j<factoradic[i];j++){
            ans+=char(i+'0');
        }
    }
    cout<<ans<<endl;
    return 0;
}
