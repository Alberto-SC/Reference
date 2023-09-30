#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int ans = 100000000;
        for(int i = 1;i<n;i++){
            ans = min(ans,nums[i]-nums[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}