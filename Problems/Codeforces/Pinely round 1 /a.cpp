#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,a,b;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        vector<int> nums(n);
        if(a+b>=n-1){
            if(a == n && b == n)cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
        else cout<<"Yes"<<endl;
    }
    return 0;
}