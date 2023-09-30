#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool solve(vector<int> nums,int turn = 0){
    if(nums[0] == 0)return !turn;
    int n = nums.size();
    bool ans = turn?0:1;
    for(int i = 1;i<n;i++){
        vector<int> copy = nums;
        copy[0]--;
        swap(copy[i],copy[0]);
        if(turn)
            ans |= solve(copy,turn^1);
        else 
            ans &= solve(copy,turn^1);
    }
    return ans;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int ans = 0;
        for(auto &c:nums)cin>>c,ans^=((c-1));
        cout<<ans<<endl;
        if(solve(nums))cout<<"BOB"<<endl;
        else cout<<"ALICE"<<endl;
    }
    return 0;
}