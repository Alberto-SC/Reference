#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        map<int,vector<int>> mp;
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++)
            mp[nums[i]].push_back(i);
        vector<int> ans(n+1,-1);
        for(auto c:mp){
            c.second.push_back(n);
            int mx = c.second[0];
            for(int i = 1;i<c.second.size();i++)
                mx = max(mx,c.second[i]-(c.second[i-1]+1));
            if(ans[mx+1]!= -1)ans[mx+1] = min(ans[mx+1],c.first);
            else
                ans[mx+1] = c.first;
        }

        for(int i = 1;i<=n;i++){
            if(ans[i] == -1 && ans[i-1] != -1)ans[i] = ans[i-1];
            else if(ans[i]!= 1 && ans[i-1]!= -1)ans[i] = min(ans[i],ans[i-1]);
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

