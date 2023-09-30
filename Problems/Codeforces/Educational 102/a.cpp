#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]<=d)cout<<"YES"<<endl;
        else{
            bool flag = true;
            for(int i = 0;i<n;i++){
                if(nums[i]>d)flag = false;
            }
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}  

