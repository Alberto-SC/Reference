#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        vector<int> ans(n);
        for(int i = 0;i<n;i+=2){
            ans[i] = -nums[i+1];
            ans[i+1] = nums[i];
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}

