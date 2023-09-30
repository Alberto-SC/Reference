#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 10000000;
        int t = -1;
        for(int i = 1;i<=200;i++){
            int sum = 0;
            for(int j = 0;j<n;j++){
                sum+= min({abs((i-1)-nums[j]),abs(i-nums[j]),abs((i+1)-nums[j])});
            }
            if(sum<ans){
                ans = sum;
                t = i;
            }
        }
        cout<<t<<" "<<ans<<endl;
    }
    return 0;
}

