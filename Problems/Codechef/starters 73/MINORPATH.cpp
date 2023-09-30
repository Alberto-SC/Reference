#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int inf = 1e9;

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0,z = 0;
        bool pos = false;
        for(int i= 22;i>=0;i--){
            z|=(1<<i);
            vector<int> v(n);
            for(int j = 0;j<n;j++){
                if(nums[j]&z)v[j] = inf;
                else v[j] = 0;
            }
            if(v[0]== inf || v[n-1] == inf){
                ans |=(1<<i);
                z^=(1<<i);
                continue;
            }
            vector<int> last;
            last.push_back(n-1);

            for(int j = n-2;j>=0;j--){
                if(v[j] == 0 && last.back()<=(j+nums[j]))last.push_back(j);
            }

            if(last.back()==0)pos = true;
            else ans|=(1<<i),z^=(1<<i);
        }
        if(!pos)ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}