#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int contar(vector<int> nums){
    int cont = 0;
    int n = nums.size();
    for(int i = 1;i<n-1;i++){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1])cont++;
        else if(nums[i]<nums[i-1] && nums[i]<nums[i+1])cont++;
    }
    return cont;
}

int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = n+10;
        if(n == 1||n == 2)ans = 0;
        for(int i = 1;i<n-1;i++){
            vector<int>nw =nums;
            nw[i] = nw[i+1];
            ans =min(ans,contar(nw));
            nw = nums;
            nw[i] = nw[i-1];
            ans = min(ans,contar(nw));
        }
        cout<<ans<<endl;
    }
    return 0;
}  

