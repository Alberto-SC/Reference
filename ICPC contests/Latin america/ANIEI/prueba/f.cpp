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
        int mx = 0,s = 0;
        for(int i = 0;i<n;i++)
            s+=nums[i],mx = max(mx,s);
        cout<<100+mx<<endl;
    }
    return 0;
}  
