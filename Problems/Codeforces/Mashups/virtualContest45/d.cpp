#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,int> mp;
        int ans = 0;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            int mn = n+1;
            int mx = 0;
            for(auto c:mp){
                mn = min(mn,c.second);
                mx = max(mx,c.second); 
            }
            int contmn = 0;
            int contmx = 0;
            for(auto c:mp){
                if(c.second==mn)contmn++;
                else if(c.second==mx)contmx++;
            }
            // if(i ==8)
                // cout<<mn<<" "<<mx<<" "<<contmn<<" "<<contmx<<endl;
            if((contmn*mn)+(contmx*mx)!=i+1)continue;
            if(mx==mn+1 && contmx==1)ans = max(ans,i+1);
            if(contmn==1 && mn==1)ans = max(ans,i+1);
            if(contmn>1 && mn==1 &&contmx ==0)ans = max(ans,i+1);
            if(contmn==1 && contmx==0)ans = max(ans,i+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
