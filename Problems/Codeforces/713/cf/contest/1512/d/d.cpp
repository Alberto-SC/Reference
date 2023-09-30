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

        vector<int> nums(n+2);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        sort(nums.begin(),nums.end());
        vector<int> used(n+2,true);
        bool flag = false;
        for(int i = 0;i<n+2;i++){
            int aux = s-nums[i];
            int diff = aux-nums[i];
            if(diff<=0)continue;
            int idx = lower_bound(nums.begin(),nums.end(),diff)-nums.begin();
            if(idx ==i)idx++;
            if(idx<n+2 &&nums[idx]==diff){
                used[i] = false;
                used[idx] = false;
                flag= true;
                break;
            }
        }
        if(!flag)cout<<-1<<endl;
        else {
            for(int i = 0;i<n+2;i++)
                if(used[i])cout<<nums[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}  
