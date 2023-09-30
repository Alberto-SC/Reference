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
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = 0, id;
        for(int i = 0;i<n;i++){
            if(nums[i]>mx){
                mx = nums[i];
                id = i+1;
            }
        }
        cout<<id<<endl;
    }
    return 0;
}