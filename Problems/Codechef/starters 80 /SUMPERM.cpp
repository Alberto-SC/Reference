#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;

    while(T--){
        cin>>n;
        if(n&1){
            cout<<-1<<endl;
            continue;
        }

        for(int i = 1;i<=n;i+=2){
            cout<<i+1<<" "<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
