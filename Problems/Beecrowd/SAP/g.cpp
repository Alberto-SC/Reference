#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    // sort(nums.begin(),nums.end());
    vector<int> vis(200,100);
    for(int i = 0;i<nums[0];i++)
        vis[i] = 0;
    
    int last = nums[0];
    for(int i = 1;i<n;i++){
        int next = -1;
        for(int k = last;k<last+nums[i];k++){
            // cout<<k<<" "<<k-nums[i]<<endl;
            if(k-nums[i]>= 0 && vis[k-nums[i]]==i-1){
                next = k;
                break;
            }
        }
        // cout<<next<<endl;
        for(int k = next;k>=next-(nums[i]-1);k--)
            vis[k] = min(i,vis[k]);
        last = next+1;
        // break;
    }
    int ans = 0;
    for(int i = 0;i<20;i++){
        if(vis[i]==100)break;
        ans++;
    }
    cout<<ans<<endl;
}   