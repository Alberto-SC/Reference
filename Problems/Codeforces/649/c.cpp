#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        vector<int> ans(n);
        set<int> pos;
        for(int i = 0;i<=2*n;i++)
            pos.insert(i);

        for(int i = 0;i<n;i++)
            pos.erase(nums[i]);

        vector<int> last(n+1);
        bool flag = true;
        for(int i = 0;i<n;i++)
            last[nums[i]] = i;

        if(nums[0] ==0){
            ans[0] = *pos.begin();
            pos.erase(pos.begin());
            if(last[0]== 0)
                pos.insert(0);
        }
        else{
            ans[1] = 0;
            pos.erase(0);
            if(last[1]==0)
                pos.insert(1);
        }

        for(int i = 1;i<n;i++){
            ans[i] = *pos.begin();
            pos.erase(pos.begin());
            if(last[nums[i]]== i){
                pos.insert(nums[i]);
            }
        }

        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}