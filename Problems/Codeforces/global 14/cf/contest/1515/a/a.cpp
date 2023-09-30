#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        sort(nums.begin(),nums.end());
        if(s ==x){
            cout<<"NO"<<endl;
        }
        else{
            s = 0;
            int r = n-1,l = 0;
            cout<<"YES"<<endl;
            for(int i = 0;i<n;i++){
                if(s+nums[l]==x)
                    s+=nums[r--],cout<<nums[r+1]<<" ";
                else
                    s+=nums[l++],cout<<nums[l-1]<<" ";
            }  

            cout<<endl;
        }
    }
    return 0;
}  
