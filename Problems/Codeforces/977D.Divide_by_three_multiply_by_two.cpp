#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> current;
vector<int> ans;
vector<bool> vis;
const int maxn = 1000;
vector<int> graph[maxn];
int n;
void dfs(int u){
    vis[u] = true;
    if(current.size()==n)ans = current;
    for(auto v:graph[u]){
        if(vis[v])continue;
        current.push_back(v);
        dfs(v);
        current.pop_back();
    }
}

signed main(){__
    cin>>n;
    vector<int> nums(n);
    map<int,int>mp;
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        mp[nums[i]] = i;
    }
    for(int i = 0;i<n;i++){
        if(mp.count(nums[i]*2))
            graph[i].push_back(mp[nums[i]*2]);
        if(nums[i] %3 == 0 && mp.count(nums[i]/3))
            graph[i].push_back(mp[nums[i]/3]);
    }
    for(int i = 0;i<n;i++){
        vis.assign(n,false);
        current.push_back(i);
        dfs(i);
        current.pop_back();
    }
    for(auto c:ans)cout<<nums[c]<<" ";
    cout<<endl;
    return 0;
}  
