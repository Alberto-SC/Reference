#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n);
        vector<int> suff(n);
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1]+(nums[i-1]>nums[i]?nums[i-1]-nums[i]:0);
        }
        for(int i = n-2;i>=0;i--){
            suff[i] = suff[i+1]+(nums[i+1]>nums[i]?nums[i+1]-nums[i]:0);
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(r>=l){
                cout<<pref[r]-pref[l]<<endl;
            }
            else {
                cout<<suff[r]-suff[l]<<endl;
            }
        }
    }
    return 0;
}