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
        for(auto &c:nums)cin>>c;;
        vector<int> copy = nums;
        vector<int> u;
        sort(copy.begin(),copy.end());
        int last = copy[0];
        u.push_back(last);
        for(int i = 0;i<n;i++){
            if(copy[i]!= last){
                last = copy[i];
                u.push_back(last);
            }
        }
        map<int,int> mp;
        for(auto &c:nums)c = lower_bound(u.begin(),u.end(),c)-u.begin(),mp[c]++;
        vector<int> b(n+2);
        for(auto c:mp){
            b[1]++;
            b[c.second+1]--;
        }
        for(int i = 0;i<n;i++)
            b[i] = b[i]+(i?b[i-1]:0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(b[i]==0)continue;
            ans+=b[i]-1;
        }
        // for(auto c:b)cout<<c<<" ";
        // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
