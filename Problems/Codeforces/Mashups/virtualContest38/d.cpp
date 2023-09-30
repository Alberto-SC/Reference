#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n;
    cin>>n;
    vector<int> M(3);
    cin>>M[0]>>M[1]>>M[2];
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> left(n);
    vector<int> rigth(n);
    const int inf =4e18;
    for(int i = 0;i<n;i++)
        left[i] = max(i?left[i-1]:-inf,M[0]*nums[i]);
    for(int i = n-1;i>=0;i--){
        rigth[i] = max(i==n-1?-inf:rigth[i+1],M[2]*nums[i]);
    }
    int ans = -inf;
    for(int i = 0;i<n;i++)
        ans = max(ans,M[1]*nums[i]+left[i]+rigth[i]);
    cout<<ans<<endl;
    return 0;
}  
