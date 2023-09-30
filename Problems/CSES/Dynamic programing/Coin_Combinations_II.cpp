#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int inf = 1e9+7;
    vector<vector<int>>DP(n+1,vector<int> (x+1,0));
    DP[0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j =0;j<=x;j++){
            DP[i][j] = DP[i-1][j];
            if(j-nums[i-1]>=0){
                (DP[i][j]+=DP[i][j-nums[i-1]])%=mod;
            }
        }
    }
    cout<<DP[n][x]<<endl;
    return 0;
}