#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        set<int> st;
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            st.insert(nums[i]*4);
        }

        
        int ans = 1e18;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int x = nums[i]+nums[j];    

                int y = *st.lower_bound(x);
                auto  it = st.lower_bound(x);
                if(it!=st.begin()){
                    it--;
                }

                mp[nums[i]]--;
                mp[nums[j]]--;
                mp[y]--;

                if(y/4<nums[j] && y/4>nums[i] && mp[nums[i]] && mp[nums[j]] && mp[y/4]){
                    ans = min(ans,abs(y-x));
                }
                mp[y/4]++;
                mp[*it/4]--
                if(*it/4<nums[j] && *it/4>nums[i] && mp[nums[i]] && mp[nums[j]] && mp[*it/4]){
                    ans = min(ans,abs(*it-x));
                }
                mp[*it/4]++;
                mp[nums[i]]++;
                mp[nums[j]]++;

            }
        }
        cout<<ans/3<<endl;
    }
    return 0;
}