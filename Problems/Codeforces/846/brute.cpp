#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    vector<int> nums(10);
    iota(nums.begin(),nums.end(),1);
    int ans = 0;
    for(int i = 0;i<10;i++){ 
        for(int j = i+1;j<10;j++){
            for(int k = j+1;k<10;k++){
                if(__gcd(nums[i],nums[k])==1){
                    ans++;
                    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}