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
        int ans = 0;
        for(int mask = 1;mask<(1<<n);mask++){
            vector<int> V;
            for(int i = 0;i<n;i++){
                if((mask>>i)&1)
                    V.push_back(nums[i]);
            }
            bool flag = true;
            for(int i = 1;i<V.size()-1;i++){
                if(V[i]>V[i-1] && V[i]>V[i+1])flag = false;
                if(V[i]<V[i-1] && V[i]<V[i+1])flag = false;
            }
            if(!flag)continue;
            if(V.size()>ans){
                for(auto c:V)cout<<c<<" ";
                cout<<endl;
            }
            ans = max(ans,(int)V.size());
        }
        cout<<ans<<endl;
    }
    return 0;
}  
