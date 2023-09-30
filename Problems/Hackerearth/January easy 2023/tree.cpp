#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 500007;
vector<int> graph[maxn];

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear();
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        for(int i = 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            graph[v].push_back(u);
            graph[u].push_back(v);
        }

        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        vector<int> vis(n);

        int mn = 1e15;
        int id = 1;
        while(pq.size()){
            auto u = pq.top();
            pq.pop();
            vis[u.second] = true;
            mn = min(mn,(id+u.first)-1);
            id++;
            for(auto v:graph[u.second]){
                if(!vis[v]){
                    pq.push({nums[v],v});
                }
            }
        }
        if(mn<n)
            cout<<0<<endl;
        else cout<<(mn-n)+1<<endl;


    }
    return 0;
}