#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;

int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy(n);
        copy = nums;
        sort(copy.begin(),copy.end());
        int idx = 0;
        int mn = 1000000007;
        for(int i = 0;i<n;i++)
            if(nums[i]<mn)idx= i,mn = nums[i];
        
        vector<bool> can(n,false);
        for(int i = 0;i<n;i++)
            if(__gcd(nums[i],nums[idx]) == mn)can[i] = true;
        bool flag = true;
        for(int i = 0;i<n;i++)
            if(!can[i] && nums[i]!= copy[i])flag = false;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

