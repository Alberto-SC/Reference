#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct Q{
    int m,id;
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main(){__
    int T = 1,n,q;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<pair<int,int>> v(n);
        for(int i =0 ;i<n;i++){
            v[i] = {i,nums[i]};
        }
        sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){
            if(a.second==b.second)return a.first<b.first;
            return a.second>b.second;
        });
        cin>>q;
        vector<Q> queries[n];
        for(int i = 0;i<q;i++){
            int k,pos;
            cin>>k>>pos;
            queries[k-1].push_back({pos-1,i});
        }


        vector<int> ans(q);
        ordered_set st;
        for(int i = 0;i<n;i++){
            st.insert(v[i].first);    
            for(int j = 0;j<queries[i].size();j++){
                auto x = queries[i][j].m;
                ans[queries[i][j].id] = nums[*st.find_by_order(x)]; 
            }
        }
        for(int i =0;i<q;i++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}