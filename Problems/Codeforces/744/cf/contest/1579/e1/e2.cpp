#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        list<int> ans;
        ans.push_front(nums[0]);
        for(int i = 1;i<n;i++){
            if(nums[i]<ans.front())
                ans.push_front(nums[i]);
            else 
                ans.push_back(nums[i]);
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
