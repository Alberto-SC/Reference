#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

signed main(){__
    int T = 1,n,k;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<pair<int,int>> ranges;
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && nums[j]==nums[i]){
                j++;
            }

            ranges.push_back({i+1,j});
            i = j;
        }

        if(k>=ranges.size()){
            cout<<0<<endl;
            vector<pair<int,int>> ans;
            k-=ranges.size();
            int idx = 0;
            while(k){
                int l = ranges[idx].first;
                int r = ranges[idx].second;
                int c = (r-l);

                int x = min(k,c);
                for(int i = l;i<=(l+x)-1;i++){
                    ans.push_back({i,i});
                }
                ans.push_back({l+x,r});
                idx++;
                k-=x;
            }
            for(int i = idx;i<ranges.size();i++)
                ans.push_back(ranges[i]);

            for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
        }
        else{
            cout<<1<<endl;
            int idx = 0;
            for(int i = 0;i<k-1;i++)
                cout<<i+1<<" "<<i+1<<endl;
            cout<<k<<" "<<n<<endl;
        }


        

    }
    
    return 0;
}
