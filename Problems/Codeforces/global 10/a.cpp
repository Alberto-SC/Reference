#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int mn = 1000000007,mx = -1;
        for(auto &c:nums)cin>>c,mn = min(mn,c),mx = max(mx,c);
        if(mn == mx)cout<<n<<endl;
        else cout<<1<<endl;

    }
    return 0;
}

