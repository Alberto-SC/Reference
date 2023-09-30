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
        sort(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        long double x = 0;
        long double y = 0;
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==mx && !cont)
                x+=nums[i],cont++;
            else 
                y+=nums[i];
        }
        x/= cont;
        y/= n-(cont);
        cout<<fixed<<setprecision(10);
        cout<<x+y<<endl;
    }
    return 0;
}  
