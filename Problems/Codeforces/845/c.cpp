#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;

    vector<int> divs[100007];

    for(int i= 1;i<=100000;i++){
        for(int div = 1;div*div<=i;div++){
            if(i%div ==0){
                divs[i].push_back(div);
                if((i/div) !=div)divs[i].push_back(i/div);
            }
        }
    }
    cin>>T;

    while(T--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
    
        sort(nums.begin(),nums.end());
        int cont = 0;
        vector<int> mp(m+1);
        int ans = 1e9;
        int l = 0,r = 0;
        while(l<n){
            while(r<n && cont !=m){
                for(int d = 0;d<divs[nums[r]].size();d++){
                    if(divs[nums[r]][d]>m)continue;

                    if(mp[divs[nums[r]][d]]== 0)cont++;
                    mp[divs[nums[r]][d]]++;
                }
                r++;
            }
            if (cont == m){
                ans = min(ans,nums[r-1]-nums[l]);
            }
            for(int d = 0;d<divs[nums[l]].size();d++){
                if(divs[nums[l]][d]>m)continue;

                if(mp[divs[nums[l]][d]]== 1)cont--;
                mp[divs[nums[l]][d]]--;
            }
            l++;
        }
        if(ans == 1e9)cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}