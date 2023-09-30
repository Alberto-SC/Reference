#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n;
    cin>>t;
    int id = 1;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = INT_MIN, mxs = 0;
        for (int i=0;i<n;i++){
            mxs+=nums[i];
            if (mx < mxs)
                mx = mxs; 
            if (mxs < 0)
                mxs = 0;
        }
        cout<<"Case #"<<id<<": "<<mx<<endl;
        id++;
    }
    return 0;
}  
