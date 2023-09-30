#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    int caso = 1;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;    
        for(int i = 1;i<n;i++){
            while(nums[i]<=nums[i-1]){
                ans++;
                nums[i]*=10;
                int x = 0;
                bool flag= false;
                for(x = 0;x<=9;x++)
                    if(nums[i]+x>nums[i-1]){flag = true;break;}
                if(flag){
                    nums[i]+=x;
                    break;
                }
            }
        }
        cout<<"Case #"<<caso<<": "<<ans<<endl;
        caso++;

    }
    return 0;
}  
