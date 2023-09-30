#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bool one = false;
        bool zero = false;
        for(int i = 0;i<n;i++){   
            if(nums[i]==1)one = true;
            if(nums[i]==0)zero = true;
        }
        
        if(!one)cout<<"YES"<<endl;
        else if(one && zero)cout<<"NO"<<endl;
        else {
            bool flag= true;
            sort(nums.begin(),nums.end());
            for(int i = 1;i<n;i++)
                if(nums[i]==nums[i-1]+1)flag = false;
            
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}   