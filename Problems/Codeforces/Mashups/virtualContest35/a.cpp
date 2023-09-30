#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,a;
    while(t--){
        cin>>n>>a;
        a--;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if((a+i)<n && (a-i)>=0){
                if(nums[a+i]==1 && nums[a-i]==1){
                    if(i ==0 )ans++;
                    else ans+=2;
                }
            }
            else if((a+i)<n && (a-i)<0){
                if(nums[a+i]==1)ans++;
            }
            else if((a+i)>=n &&(a-i)>=0){
                if(nums[a-i]==1)ans++;
            }
            else break;

        }
        cout<<ans<<endl;
    }
    return 0;
}  
