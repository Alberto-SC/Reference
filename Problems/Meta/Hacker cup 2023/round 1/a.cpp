#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int T= 1,n;
    int id = 1;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        
        sort(nums.begin(),nums.end());
        cout<<fixed<<setprecision(6);
        if(n == 5){
            long double d1 = (nums[0]+nums[2])/2.0;
            long double d2 = (nums[n-1]+nums[n-2])/2.0; 

            long double d3 = (nums[0]+nums[1])/2.0;
            long double d4 = (nums[n-1]+nums[n-3])/2.0;


            long double ans1 = d2-d1;
            long double ans2 = d4-d3;

            cout<<"Case #"<<id<<": "<<max(ans1,ans2)<<endl; 
        }
        else{

            long double d1 = (nums[0]+nums[1])/2.0;
            long double d2 = (nums[n-1]+nums[n-2])/2.0; 
        
            cout<<"Case #"<<id<<": "<<d2-d1<<endl;
        }
        id++;
    }
    return 0;
}  

