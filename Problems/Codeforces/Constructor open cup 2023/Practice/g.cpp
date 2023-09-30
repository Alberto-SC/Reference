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
        for(auto &c:nums)cin>>c;
        
        int last = nums[n-1];

        bool flag = true;
        for(int i= n-2;i>=0;i--){
            if(nums[i]<=last){
                last = nums[i];
                continue;
            }
            
            int m = nums[i]/2;
            
            if(m+(nums[i]&1)>last){
                flag = false;
                break;
            }
            last = m;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
