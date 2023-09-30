#include <bits/stdc++.h>
using namespace std;
const int Nmax = 5007;
int dp[Nmax][Nmax];
int LCS(vector<int> a,vector<int>b){
    int n = a.size();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(a[i-1] == b[j-1])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int main(){
    int n,ai;
    cin>>n;
    vector<int> nums(1);
    for(int i = 0;i<n;i++){
        cin>>ai;
        if(ai!= nums.back())nums.push_back(ai);
    }
    vector<int> b;
    nums.erase(nums.begin());
    b = nums;
    reverse(b.begin(),b.end());
    int lcs = LCS(nums,b);
    int ans = b.size()-((lcs+1)/2);
    cout<<ans<<endl;
}