#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int DP[207][407];
vector<int> nums;
const int inf = 500*500;
int solve(int i,int k){
    if(k<=0 && i>=0)return inf;
    if(i <0)return 0;
    int &x = DP[i][k];
    if(x!=-1)return x;
    int ans = min(solve(i-1,k-1)+abs(nums[i]-k),solve(i,k-1));
    return x = ans;
}

int main(){
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        nums.resize(n);
        for(auto &c:nums)cin>>c;
        memset(DP,inf,sizeof(DP));
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++)
            for(int j = 0;j<=2*n;j++)
                DP[i][j] = -1;
        
        solve(n-1,2*n);
        cout<<DP[n-1][2*n]<<endl;
    }
    return 0;
}
