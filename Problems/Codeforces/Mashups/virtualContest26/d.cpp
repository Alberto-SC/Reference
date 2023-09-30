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
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        int need = sum/n;
        int moves = 0;
        for(int i = 0;i<n-1;i++){
            moves+=abs(nums[i]-need);
            nums[i+1]+= nums[i]-need;
        }
        cout<<moves<<endl;
    }
    return 0;
}  
