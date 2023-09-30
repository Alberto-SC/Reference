#include <bits/stdc++.h>
using namespace std;
const int maxn = 2007;
const int maxk = 22;
int DP[maxn][maxk];
const int  inf = 1000000000;
int n;
vector<int> ac(maxn);
int cost(int i,int j){
    int sum;
    if(i)
        sum = ac[j]-ac[i-1];
    else 
        sum = ac[j];
    if(sum%10<5)sum-=sum%10;
    else sum+=10-sum%10;
    return sum;
}
//  return min or max of proffit cutting an array in exactly k parts
//  Complexity O(n^2 *k * cost)
int solve(int idx,int k){
    if(k==0 && idx==n)return 0;
    else if(k == 0 && idx<n)return inf+1;
    int &x = DP[idx][k];
    if(x!= inf)return x;
    for(int i = idx;i<n;i++)
        x = min(x,cost(idx,i)+solve(i+1,k-1));
    
    return x;
}

int main(){
    int k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<=k+1;j++)DP[i][j] = inf;
    ac[0] = nums[0];
    for(int i = 1;i<n;i++)
        ac[i] = ac[i-1]+nums[i];    

    for(int i = 0;i<n;i++)
        DP[i][1] = cost(i,n-1);
    for(int i = 0;i<=k;i++)
        DP[n][i] = 0;

    solve(0,k+1);
    // for(int i = 0;i<=n;i++)
        // for(int j = 0;j<=k+1;j++)
            // cout<<DP[i][j]<<" \n"[j == k+1];
    cout<<DP[0][k+1]<<endl;
    return 0;
}