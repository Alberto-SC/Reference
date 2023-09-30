#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        vector<int> nums(4);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        sort(copy.rbegin(),copy.rend());
        int win1 = max(nums[0],nums[1]);
        int win2 = max(nums[2],nums[3]);
        if(win1<win2)swap(win1,win2);
        if(win1==copy[0] &&win2 == copy[1])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
