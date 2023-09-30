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
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        int posmn,posmx;
        for(int i = 0;i<n;i++){
            if(nums[i]==mn)posmn = i;
            if(nums[i]==mx)posmx = i;
        }
        int lr = min(posmn+1,posmx+1)+(n-(max(posmx,posmn)));
        cout<<min({max(posmn,posmx),(n-min(posmx,posmn)),lr})<<endl;
    
    }
    return 0;
}  
