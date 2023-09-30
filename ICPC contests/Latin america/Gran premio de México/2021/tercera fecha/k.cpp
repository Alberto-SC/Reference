#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,T,D,M;
    while(t--){
        cin>>T>>D>>M;
        vector<int> nums(M);
        for(auto &c:nums)cin>>c;
        nums.push_back(0);
        nums.push_back(D);
        sort(nums.begin(),nums.end());
        bool flag =false;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>=T)flag = true;
        }
        if(flag)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}  
