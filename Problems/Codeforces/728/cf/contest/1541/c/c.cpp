#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<pair<int,int>> graph[maxn];
int lastd = 0;
int restar = 0;
void dfs(int u,int p = -1,int d = 0){
    for(auto v:graph[u]){
        restar+=(v.second*(d+1))+lastd;
        lastd += (v.second*(d+1));
        dfs(v.first,u,d+1);
    }
}


signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(int i = 0;i<=n+1;i++)
            graph[i].clear();
        for(auto &c:nums)cin>>c;
        vector<pair<int,int>> nodes(n);
        for(int i = 0;i<n;i++){
            nodes[i] = {nums[i],i};
        } 
        sort(nodes.begin(),nodes.end());    
        int sum = 0,last = 0,ans = 0;
        for(int i = 1;i<n;i++){
            graph[last].push_back({nodes[i].second,nodes[i].first-sum});
            ans+=nodes[i].first-sum;
            sum+=nodes[i].first-sum;
            last = nodes[i].second;
        }
        lastd = 0;
        restar = 0;
        dfs(0);
        cout<<ans-restar<<endl;
    }
    return 0;
}  
