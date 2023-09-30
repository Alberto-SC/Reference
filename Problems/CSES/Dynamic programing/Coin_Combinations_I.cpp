#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int inf = 1e9+7;
    vector<int >DP(x+1,0);
    DP[0] = 0;
    for(int i = 0;i<n;i++)if(nums[i]<=x)DP[nums[i]] = 1;
    for(int i =1;i<=x;i++){
        for(int j = 0;j<n;j++){
            if(i-nums[j]>=0){
                
                (DP[i] +=DP[i-nums[j]] ?DP[i-nums[j]]:0)%=mod;
            }

        }
    }
    // for(auto c:DP)cout<<c<<" ";
    // cout<<endl;
    cout<<DP[x]<<endl;
    return 0;
}