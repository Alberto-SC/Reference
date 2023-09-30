#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int cont = 0;
        vector<int> nums(n);
        int mn = 1e12;
        for(auto &c:nums)cin>>c,cont+=c,mn = min(mn,c);

        if(cont%2 == 0 && n&1)cout<<"CHEFINA"<<endl;
        else if(cont%2 == 0 && n%2 == 0 && mn%2 == 0)cout<<"CHEFINA"<<endl;
        else cout<<"CHEF"<<endl;
    }
    return 0;
}