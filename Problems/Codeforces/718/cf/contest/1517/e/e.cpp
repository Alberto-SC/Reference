#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 998244353;
int s = 0;
int solve(int idx,int s,int lastc,int lastp){
    if(idx ==n){
        if(s<sum-s)return 1;
        else return 0;
    }
    if(DP[idx].count({lastc,lastp}))return DP[idx][{lastc,lastp}];
     
}

signed main(){__
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,s+=c;
    return 0;
}  
