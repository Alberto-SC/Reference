#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        vector<int> a(3);
        cin>>a[0]>>a[1]>>a[2];
        sort(a.begin(),a.end());
        if(a[1]+a[2]>=10 )cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}