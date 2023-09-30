#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,a,b,c,d;
    cin>>t;
    while(t--){
        vector<int> nums(4);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        cout<<nums[0]*nums[2]<<endl;
    }
    return 0;
}  

