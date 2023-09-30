#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        bitset<1007> bs;
        bs[1] = 1;

        sort(nums.begin(),nums.end());
        
        int last = 1;

        if(nums[0]!=1){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        for(int i = 1;i<n;i++){
            if(last<nums[i]){
                flag = false;
                break;
            }
            last+=nums[i];
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

