#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n,q;
    cin>>T;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1;i<n;i++)
            pref[i] = pref[i-1]+nums[i];

        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            l--,r--;

            int L = l?pref[l-1]:0;
            int R = pref[n-1]-pref[r];

            int s = ((r-l)+1)*k;

            if((L+R+s) &1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

        }
    }
    return 0;
}

