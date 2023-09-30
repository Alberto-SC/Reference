#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bool flag = true;
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return a%2<b%2;
        });
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(__gcd(nums[i],2*nums[j])>1)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
