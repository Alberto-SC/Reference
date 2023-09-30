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
        nums.push_back(nums.back());
        vector<int> y(n+1);
        for(int i = 0;i<n;i++){
            int yi = 0;
            if(((nums[i]^y[i]) & (nums[i+1]^y[i+1])) == (nums[i]^y[i]))continue;
            else{
                for(int j = 0;j<30;j++){
                    if(((nums[i]^y[i])>>j)&1 && !(((nums[i+1]^y[i+1])>>j)&1)){
                        yi|= 1<<j;
                    }
                }
            }
            y[i+1] = yi;
        }
        for(int i = 0;i<n;i++)
            cout<<y[i]<<" ";
        cout<<endl;
    }
    return 0;
}  
