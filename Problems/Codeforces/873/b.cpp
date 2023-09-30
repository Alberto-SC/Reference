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
        vector<int> nums(n+1);
        for(int i = 1;i<=n;i++)cin>>nums[i];

        vector<int> vis(n+1);
        set<int> st;

        bool flag = true;
        for(int i = 1;i<=n;i++){
            if(vis[i])continue;
            vector<int> cycle;
            int cur = i;
            while(!vis[cur]){
                vis[cur] = 1;
                cycle.push_back(cur);
                cur = nums[cur];
            }
            sort(cycle.begin(),cycle.end());

            set<int> s;
            int gcd = 0;
            for(int j = 1;j<cycle.size();j++){
                gcd = __gcd(gcd,cycle[j]-cycle[j-1]);
            }

            if(gcd!= 0)st.insert(gcd);
        }

        int gcd = 0;
        for(auto c:st){
            gcd = __gcd(gcd,c);
        }
        cout<<gcd<<endl;
    }
    return 0;
}