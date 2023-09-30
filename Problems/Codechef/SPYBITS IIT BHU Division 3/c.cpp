#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,q,x,k;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        cin>>q;
        vector<int> last(n);
        int ans = 0;
        iota(last.begin(),last.end(),0);
        for(int i = 0;i<q;i++){
            cin>>x>>k;
            x--;  
            ans = 0;
            int first = last[x];
            while(k){
                while(last[x]<n && !nums[last[x]]){
                    last[x]++;
                }
                if(last[x]==n)break;
                int mn = min(k,nums[last[x]]);
                ans+=(last[x]-x)*mn;
                k-=mn;
                nums[last[x]]-=mn;
            }
            int j = first;
            while(j<n&& nums[j]==0){
                last[j] = last[x];
                j++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}  
