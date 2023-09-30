#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>n;
    vector<int> nums(n-1);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    int x = nums[0];
    int miss = -1;
    for(int i= 1;i<n-1;i++){
        if(nums[i]!=x+1){
            miss = x+1;
            break;
        }
        x++;
    }
    if(miss==-1)cout<<"IMPOSSIBLE"<<endl;
    else cout<<miss<<endl;

    return 0;
}