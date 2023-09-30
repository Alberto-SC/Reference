#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int DP[maxn][maxn][6][2];
vector<lli> nums;
int n;
lli mx = -1;
int solve(int x,int k,int z,int dir,lli sum){
    if(x>=n)return 0;
    if(k<0)return 0;
    if(x<0)return 0;
    if(z<0)return 0;
    
    DP[x][k][z][dir]= max(nums[x];
    if(sum>mx)mx = sum;
    if(dir){
        solve(x+1,k-1,z,1,sum);
        if(z)
            solve(x-1,k-1,z-1,0,sum);
    }
    else solve(x+1,k-1,z,1,sum);
}

int main(){__
    int t,k,z;
    cin>>t;
    while(t--){
        cin>>n>>k>>z;
        nums.assign(n,0);
        for(auto &c:nums)cin>>c;
        mx = -1;
        solve(0,k,z,1,0);
        cout<<mx<<endl;
    }
    return 0;
}