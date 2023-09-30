#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
    
        vector<int> nums(n);
        vector<int> v(n);
        iota(v.begin(),v.end(),1);
        for(auto &c:nums)cin>>c;
        
        int id = 1;
        for(int i = 0;i<n-1;i++){
            if(nums[i]<id)break;

            int x = nums[i]-id;
            nums[i] = id;
            nums[i+1]+=x;
            id++;
        }

        if(v !=nums)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
    return 0;
}
