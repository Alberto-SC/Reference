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
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(copy[i]==nums[i])cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}  
