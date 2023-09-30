#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,q,type,id;
    while(t--){
        cin>>n>>q;
        vector<int> nums(n);
        int ones = 0;
        for(auto &c:nums)cin>>c,ones+=c;
        for(int i = 0;i<q;i++){
            cin>>type>>id;
            if(type == 1){
                id--;  
                if(nums[id] == 1)
                    ones--;
                else
                    ones++;
                nums[id]^=1;
            }
            else{
                if(id<=ones)cout<<1<<endl;
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}  
