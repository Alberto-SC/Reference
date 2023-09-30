#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        int c,d;
        cin>>n>>c>>d;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        
        sort(nums.begin(),nums.end());
        int need = 0;
        vector<int> E;
        vector<int> v;
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && nums[j] == nums[i])j++;

            int len = j-i;

            if(E.size())E.push_back(E.back()+(len-1)*c);
            else E.push_back((len-1)*c);
            v.push_back(nums[i]);
            i = j;
        }

        int ans = (n*c)+d;
        int N = v.size();

        for(int i = 0;i<N;i++){
            int rem = upper_bound(nums.begin(),nums.end(),v[i])-nums.begin();
            rem = n-rem;
            /* cout<<v[i]<<" "<<E[i]<<" "<<v[i]-(i+1)<<" "<<rem<<endl; */
            ans = min(ans,E[i]+((v[i]-(i+1))*d)+(rem*c));
        }

        cout<<ans<<endl;
    }
}


