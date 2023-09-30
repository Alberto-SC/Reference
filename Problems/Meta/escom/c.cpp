#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    int test = 1;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mn  =0,mx = -1e15,ac = 0,mxn = -1e15;
        for(int i = 0;i<n;i++){
            ac+=nums[i];
            mn = min(ac,mn);
            mx = max(mx,ac-mn);
            mxn = max(mxn,nums[i]);
        }
        if(mxn<0)cout<<"Case #"<<test<<": "<<mxn<<endl;
        else 
            cout<<"Case #"<<test<<": "<<mx<<endl;
        test++;
    }
    return 0;
}  
