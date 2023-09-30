#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        priority_queue<int> q;

        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]  == 0){
                if(q.empty())continue;
                ans+=q.top();
                q.pop();
            }
            else {
                q.push(nums[i]);
            }
        }
        cout<<ans<<endl;
    }
    
}

