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
        int l = 0;
        while(l<n && nums[l]==l+1){
            l++;
        }
        int r = n-1;
        while(r>=0 && nums[r]==r+1){
            r--;
        }
        if(l ==n)cout<<"0 0"<<endl;
        else {
            reverse(nums.begin()+l,nums.begin()+r+1);
            bool flag = true;
            for(int i = 0;i<n;i++){
                if(nums[i]!= i+1)flag = false;
            }
            if(flag)
                cout<<l+1<<" "<<r+1<<endl;
            else cout<<"0 0"<<endl;
        }
    }
    return 0;
}  
