#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<string> nums(n);
        for(auto &c:nums)cin>>c;
        cout<<nums[0]<<endl;
    }
    return 0;
}  
