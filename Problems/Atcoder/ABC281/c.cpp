#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1]+nums[i];
        }
        k%=pref[n-1];
        int id = 0,x = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]>k){  
                id = i+1;
                break;
            }
            k-=nums[i];
        }
        cout<<id<<" "<<k<<endl;
    }
    return 0;
}