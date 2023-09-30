#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int DP[60]; 
int n;
vector<int> nums(60);
int solve(int i){
    if(i>=n)return 0;
    int &x = DP[i];
    if(x!=-1)return x;
    int ans = max(solve(i+1),solve(i+2)+nums[i]);
    return x = ans;
}
int main(){__
    int t = 1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)
            cin>>nums[i];
        memset(DP,-1,sizeof(DP));
        cout<<solve(0)<<endl;
    }
    return 0;
}      
