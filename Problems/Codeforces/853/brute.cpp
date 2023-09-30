#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int total = ((m*(m+1))/2)*2*n;

        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
       
        vector<pair<int,int>> last(n+m+7);
        
        for(auto c:nums)
            last[c] = {m+1,0};

        vector<vector<int>> v;
        v.push_back(nums);
        for(int i = 1;i<=m;i++){
            int p,x;
            cin>>p>>x;
            p--;
            nums[p] = x;
            v.push_back(nums);
        }
        int ans = 0;
        for(int i = 0;i<v.size();i++){
            for(int j = i+1;j<v.size();j++){
                set<int> st;

                for(int k = 0;k<v[i].size();k++)
                    st.insert(v[i][k]);
                for(int k = 0;k<v[j].size();k++)
                    st.insert(v[j][k]);
                ans+=st.size();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

