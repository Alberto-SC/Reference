#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        int mn = 1e9;
        int idx;
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            if(nums[i]<mn){
                mn = nums[i];
                idx = i;
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i ==idx)continue;
            ans+= (k-nums[i])/mn;
        }
        cout<<ans<<endl;
    }
    return 0;
}

