#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


struct query{
    int x,nw;
};
int main(){__
    int n,m,x,nw;
    cin>>n>>m;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    vector<int> nums(n);
    vector<int> compress;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        compress.push_back(nums[i]);
        // mp[nums[i]].insert(i);
    }
    vector<query> Q;
    for(int i = 0;i<m;i++){
        cin>>x>>nw;
        Q.push_back({x,nw});
        compress.push_back(nw);
    }
    sort(compress.begin(),compress.end());
    vector<int> unique;
    int last = compress[0];
    unique.push_back(last);
    for(int i = 0;i<compress.size();i++){
        if(compress[i]!= last){
            last = compress[i];
            unique.push_back(last);
        }
    }
    vector<ordered_set> mp(unique.size()+10);
    for(int i = 0;i<n;i++){
        nums[i] = lower_bound(unique.begin(),unique.end(),nums[i])-unique.begin();
        mp[nums[i]].insert(i);
    }

    for(int i = 0;i<m;i++){
        x = Q[i].x, nw = Q[i].nw;
        nw = lower_bound(unique.begin(),unique.end(),nw)-unique.begin();
        cout<<mp[nw].order_of_key(x)<<endl;
        mp[nums[x]].erase(x);
        mp[nw].insert(x);
        nums[x] = nw;
    }
    return 0;
}