#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<lli> DP(n);
        lli mx = 0;
        for(int i = n-1;i>=0;i--){
            if(i+nums[i]>=n){
                DP[i] = nums[i];
            }
            else{
                DP[i] = nums[i]+DP[i+nums[i]];
            }
            mx = max(DP[i],mx);
        }
        cout<<mx<<endl;
    }
    return 0;
}  

