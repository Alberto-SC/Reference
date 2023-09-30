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
        nums[n-1] = n;
        nums[n-2] = n-1;
        int s = 1;
        for(int i= n-3;i>=0;i--){
            nums[i] = s++;
        }
        if(n&1)swap(nums[0],nums[1]);
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}