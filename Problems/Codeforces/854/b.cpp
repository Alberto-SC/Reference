#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c; 

        
        set<pair<int,int>> st;
        bool one = false,none = false;
        for(int i = 0;i<n;i++){
            if(nums[i]==1)one = true;
            else none = true;
            st.insert({nums[i],i+1});
        }
        
        if(one && none){
            cout<<-1<<endl;
            continue;
        }

        int ans = 0;
        vector<pair<int,int>> op;

        while(1){
            pair<int,int> mn = *st.begin();
            pair<int,int> mx = *st.rbegin();
           
            if(mx.first == mn.first)break;
            pair<int,int> nw = {(mx.first+(mn.first-1))/mn.first,mx.second};
            op.push_back({mx.second,mn.second});
            st.erase(mx);
            st.insert(nw);
            ans++;
        }
        cout<<ans<<endl;
        for(auto c:op)cout<<c.first<<" "<<c.second<<endl;
        cout<<endl;
            

    }
    return 0;
}

