#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    while(T--){
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,int> mp;
        bool flag = false;
        for(int i = 0;i<n;i++){
            int need = x-nums[i];
            if(mp.count(need)){
                flag = true;
                cout<<mp[need]+1<<" "<<i+1<<endl;
                break;
            }
            mp[nums[i]] = i;
        }
        if(!flag)cout<<"IMPOSSIBLE"<<endl;

    }
    return 0;
}