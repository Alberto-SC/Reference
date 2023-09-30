#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
const int inf = 1e9;
int DP[2][maxn];
vector<int> nums(maxn,0);
int n;
int solve(int idx,int turn ){
    // cout<<idx<<" "<<turn<<endl;
    if(idx>=n)return 0;
    int &x = DP[turn][idx];
    if(x != inf)return x;
    if(!turn)
        x = min(solve(idx+1,!turn)+nums[idx], solve(idx+2,!turn)+nums[idx]+nums[idx+1]);
    else 
        x = min(solve(idx+1,!turn),solve(idx+2,!turn));
    return x;
}

int main(){__
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<=n;i++)DP[0][i] = DP[1][i]= inf; 
        for(int i = 0;i<n;i++)
            cin>>nums[i];
        solve(0,0);
        // for(int i = 0;i<n;i++)
            // cout<<DP[i]<<" ";
        // cout<<endl;
        cout<<DP[0][0]<<endl;
    }
    return 0;
}

