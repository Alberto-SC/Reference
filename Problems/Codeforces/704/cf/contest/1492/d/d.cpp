/**

 * Author: LCSB
 * Time: 2021-02-23 12:13:07

**/
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
        bool flag = true;
        cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}  
