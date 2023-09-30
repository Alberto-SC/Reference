#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int inf = 1e9+7;
    vector<int >DP(x+1,inf);
    DP[0] = 0;
    for(int i =1;i<=x;i++){
        for(int j = 0;j<n;j++){
            if(i-nums[j]>=0)
                DP[i] = min(DP[i],DP[i-nums[j]]+1);
        }
    }
    if(DP[x]==inf)return cout<<-1<<endl,0;
    cout<<DP[x]<<endl;
    return 0;
}