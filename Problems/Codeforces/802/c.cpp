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
        int mn = 1e12,id;
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            if(nums[i]<mn){
                mn = nums[i];
                id = i;
            }
        }
        int ans = 0,ac = 0;  
        for(int i = id+1;i<n;i++){
            int x = nums[i]-nums[i-1];
            if(x<0)ac+=x;
        }
        // cout<<ac<<" "<<nums[n-1]-(nums[id]+ac)<<endl;
        ans+=abs(ac)+(nums[n-1]-(nums[id]+ac));
        int ac2 = 0;
        for(int i =id-1;i>= 0;i--){
            int x = nums[i]-nums[i+1];
            if(x<0)ac2+=x;
        }
        // cout<<ac2<<" "<<(nums[0]+ac)-(nums[id]+ac2+ac)<<endl;
        ans+=abs(ac2)+((nums[0]+ac)-(nums[id]+ac2+ac));
        ans+=abs(nums[id]+ac2+ac);
        cout<<ans<<endl;
    }
    return 0;
}