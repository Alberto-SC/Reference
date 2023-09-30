#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    cin>>T;
    while(T--){
        cin>>n>>x;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s%x){
            cout<<n<<endl;
            continue;
        }

        int mn = n+1;
        s = 0;
        for(int i = 0;i<n;i++){
            s+=nums[i];
            if(s%x){
                mn = i+1;
                break;
            }
        }
        s = 0;
        for(int i = n-1;i>=0;i--){
            s+=nums[i];
            if(s%x){
                mn = min(mn,n-i);
                break;
            }
        }
        cout<<n-mn<<endl;
    }
    return 0;
}