#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,a,b;
    while(T--){
        cin>>a>>b;
        int x = 1;
        for(int i = 0;i<b;i++){
            x*=a;
        }
        cout<<x<<endl;
    }
    return 0;
}