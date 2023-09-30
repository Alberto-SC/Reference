#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        stack<pair<int,int>> s;
        vector<int> pos(n);
        for(int i = 0;i<n;i++){
            while(!s.empty()&& nums[i]>s.top().first){
                auto x = s.top();
                s.pop();
                pos[x.second] = i;
            }
            s.push({nums[i],i});
        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            if(pos[i]==0||pos[i]==i+1)ans++;
            else ans+=2;
        }
        reverse(nums.begin(),nums.end());
        while(!s.empty()){
            s.pop();
        }
        pos.assign(n,0);
         for(int i = 0;i<n;i++){
            while(!s.empty()&& nums[i]>s.top().first){
                auto x = s.top();
                s.pop();
                pos[x.second] = i;
            }
            s.push({nums[i],i});
        }
        for(int i = 0;i<n-1;i++){
            if(pos[i]==0 ||pos[i]==i+1)ans+=0;
            else ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
