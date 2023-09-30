#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    while(T--){
        cin>>n>>q;
        vector<int> nums[n];
        for(int i = 0;i<n;i++){
            int l;cin>>l;
            for(int j = 0;j<l;j++){
                int x;cin>>x;
                nums[i].push_back(x);
            }
        }
        while(q--){
            int a,b;
            cin>>a>>b;
            cout<<nums[a-1][b-1]<<endl;
        }
    }
    return 0;
}
