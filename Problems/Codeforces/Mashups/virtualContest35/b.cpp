#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
signed main(){__
    int n;
    int nums[6];
    cin>>nums[0]>>nums[1];
    for(int i = 2 ;i<6;i++)
        nums[i] = nums[i-1]-nums[i-2];
    cin>>n;
    cout<<(nums[(n-1)%6]%mod+mod)%mod<<endl;
    return 0;
}  
