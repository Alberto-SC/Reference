#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,s;
    cin>>t>>s>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int U = s;
    int B = 0;
    for(int i =1;i<n;i++){
        int Pass = nums[i]-nums[i-1];
        U = max(U-Pass,0ll);
        B = min(s,B+Pass);
        swap(U,B);
    }
    int last = nums.back();
    cout<<max(U-(t-last),0ll)<<endl;
    return 0;
}  
