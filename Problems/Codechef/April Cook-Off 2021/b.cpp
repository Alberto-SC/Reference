#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,v,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> one(32);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<32;j++){
                if((nums[i]>>j)&1)one[j]++;
            }
        }
        int ans = 0;
        for(int i = 0;i<32;i++)
            if(one[i])ans+= (1<<i);
        
        cout<<ans<<endl;
        for(int i = 0;i<q;i++){
            cin>>x>>v;
            x--;
            for(int j = 0;j<32;j++)
                if((nums[x]>>j)&1)one[j]--;
            nums[x]= v;
            for(int j = 0;j<32;j++)
                if((nums[x]>>j)&1)one[j]++;
            ans = 0;
            for(int j = 0;j<32;j++)
                if(one[j])ans+= (1<<j);
            cout<<ans<<endl;
        }
    }
    return 0;
}  
