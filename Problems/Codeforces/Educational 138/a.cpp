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
        int x,y;
        for(int i = 0;i<m;i++){
            cin>>x>>y;
        }
        if(m ==n)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}