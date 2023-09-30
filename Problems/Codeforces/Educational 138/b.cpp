#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> h(n),b(n);
        int sum = 0;
        for(auto &c:h)cin>>c,sum+=c;
        for(auto &c:b)cin>>c,sum+=c;
        int mx = *max_element(b.begin(),b.end());
        cout<<sum-mx<<endl;
    }
    return 0;
}