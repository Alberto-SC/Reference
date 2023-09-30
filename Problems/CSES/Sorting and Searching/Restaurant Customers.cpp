#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<pair<int,int>> nums(n);
        for(auto &[x,y]:nums)cin>>x>>y;
        vector<pair<int,int>> events;
        for(int i = 0;i<n;i++){
            events.push_back({nums[i].first,-1});
            events.push_back({nums[i].second,+1});
        }
        sort(events.begin(),events.end());
        int cont = 0,ans = 0;
        for(int i = 0;i<events.size();i++){
            cont+=events[i].second*-1;
            ans = max(ans,cont);
        }
        cout<<ans<<endl;
    }
    return 0;
}