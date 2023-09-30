#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int DP[57][50007];
int n,B,M;
vector<int> nums;
const int inf = -10000;
int solve(int idx,int sum){
    if(sum>M|| sum<0)return inf;
    if(idx == n)return sum;
    int &x = DP[idx][sum];
    // cout<<idx<<" "<<sum<<" "<<M<<" "<<x<<endl;
    if(x!= inf)return x;
    x = max({x,solve(idx+1,sum+nums[idx]),solve(idx+1,sum-nums[idx])});
    return x;
}

int main(){__
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    cin>>B>>M;
    for(int i = 0;i<57;i++)
        for(int j = 0;j<50007;j++)
            DP[i][j] = inf;
    solve(0,B);
    if(DP[0][B] == inf)cout<<-1<<endl;
    else cout<<DP[0][B]<<endl;
    return 0;
}