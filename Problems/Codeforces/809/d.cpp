#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> v[mx+3];
        for(int i = 0;i<n;i++){
            unordered_set<int> s;
            
            if(k> nums[i]){
               s.insert(0);
            }
            for (int d = 1; d <= sqrt(nums[i]); d++) {
                
                
                int l = nums[i]/(d+1);
                l++;
                if(l<=k)s.insert(d);

                l  = nums[i]/((nums[i]/d)+1);
                l++;
                if(l<=k)s.insert(nums[i]/d);     

            }
            for(auto c:s){
                v[c].push_back(i);
            }
        }

        vector<int> used(n);

        int l = 0,r = 0,cont = 0,ans = 1e9;
        while(l<=mx){
            while(r<=mx && cont!=n){
                for(int i = 0;i<v[r].size();i++){
                    used[v[r][i]]++;
                    if(used[v[r][i]]==1)cont++;
                }
                r++;
            }
            if(cont == n)
                ans = min(ans,r-l-1);
            

            for(int i = 0;i<v[l].size();i++){
                used[v[l][i]]--;
                if(used[v[l][i]]==0)cont--;
            }
            l++;
        }
        cout<<ans<<endl;

    }
    return 0;
}