#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(int i = 0;i<n;i++)
            nums[i] = n-i;
        if(n&1)
            swap(nums[n/2],nums[(n/2)-1]);
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

