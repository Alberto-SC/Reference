#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,k,x;
    cin>>t;
    while(t--){ 
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> mxs[n+1];
        int mx = 0;
        for(int i = 0;i<n;i++){
            int s = 0;
            for(int j = i;j<n;j++){
                s+=nums[j];
                mx = max(mx,s);
                mxs[(j-i)+1].push_back(s);
            }
        }
        for(int i = 1;i<=n;i++)
            sort(mxs[i].rbegin(),mxs[i].rend());
    
        vector<int> ans(n+1);
        ans[0] =max(0ll,mx);
        for(int i = 1;i<=n;i++){
            ans[i] = ans[i-1];
            for(int j = 1;j<=n;j++){
                ans[i] = max(ans[i],mxs[j][0]+(min(i,j)*x));
            }
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}