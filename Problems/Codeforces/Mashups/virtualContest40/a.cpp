#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int sum= 0;
        for(int i = 0;i<k;i++){
            sum+=nums[i];
        }
        int ans =1e15;
        int idx = 0;
        for(int i = 0;i<=(n-k);i++){
            if(sum<ans){
                ans = sum;
                idx = i+1;
            }
            sum-=nums[i];
            sum+=nums[i+k];
        }
        cout<<idx<<endl;
    }
    return 0;
}  
