#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
 
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int a = 0,b = 0;
        for(auto &c:nums){
            cin>>c;
            if(c&1)b+=c;
            else a+=c;
        } 
        if(a>b)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
            
    }
    return 0;
}

