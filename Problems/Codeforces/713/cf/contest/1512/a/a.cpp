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
        vector<int> o(200);
        for(int i = 0;i<n;i++){
            o[nums[i]]++;
        }
        int diff = -1;
        for(int i = 0;i<200;i++){
            if(o[i]==1)diff = i;
        }
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==diff)idx = i+1;
        }
        cout<<idx<<endl;
    }
    return 0;
}  
