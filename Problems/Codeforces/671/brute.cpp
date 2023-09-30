#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli gauss(lli n){
    return (n*(n+1))/2;
}
int main(){__
    lli t = 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> ans(n);
    int mx = -1;
    sort(nums.begin(),nums.end());
    do{ 
        int res =0;
        for(int i = 1;i<n-1;i++){
            if(nums[i]<nums[i+1] && nums[i]<nums[i-1])res++;
        }
        if(res>mx)
            ans = nums,mx = res;
    
    }while(next_permutation(nums.begin(),nums.end()));
    cout<<mx<<endl;
    // sort(nums.begin(),nums.end());
    // do{ 
    //     int res =0;
    //     for(int i = 1;i<n-1;i++){
    //         if(nums[i]<nums[i+1] && nums[i]<nums[i-1])res++;
    //     }
    //     if(res==mx){
    //         for(auto c:nums)
    //             cout<<c<<" ";
    //         cout<<endl;
    //     }
    
    // }while(next_permutation(nums.begin(),nums.end()));
    return 0;
}

