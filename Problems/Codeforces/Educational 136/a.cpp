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
        if(n == 1 || m ==1)cout<<1<<" "<<1<<endl; 
        else cout<<"2 2"<<endl;
    }
    return 0;
}