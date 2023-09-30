#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        for(auto &x:nums)cin>>x;
        lli mx = INT_MIN, max_here = 0; 
        for (int i = 0; i < n-1; i++){ 
            max_here = max_here + nums[i]; 
            if (mx < max_here) 
                mx = max_here;  ,
            if (max_here < 0) 
                max_here = 0; 
        } 
        lli mx2 = INT_MIN;
        max_here = 0;
        for (int i = 1; i < n; i++){ 
            max_here = max_here + nums[i]; 
            if (mx2 < max_here) 
                mx2 = max_here; 
            if (max_here < 0) 
                max_here = 0; 
        }
        lli total = accumulate(nums.begin(),nums.end(),0ll);
        if(mx<total && mx2< total)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}