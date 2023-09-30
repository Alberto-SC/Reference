#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n,m;
int DP[1000][n]

signed main(){__
    cin>>n>>m;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int ans = 0;
    for(int i = 0;i<n;i++)
        ans+= solve(i,0).size();
    
    cout<<ans<<endl;
    return 0;
}  
