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
        int a = 0,b = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==1)a++;
            else if(nums[i]==2)b--;
            if(nums[i]==3)a++;
        }
        cout<<a<<endl;
    }
    return 0;
}  
