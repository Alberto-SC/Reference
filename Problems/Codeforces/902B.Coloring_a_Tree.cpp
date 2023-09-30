#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> c;
const int maxn = 100007;
vector<int> graph[maxn];
int ans = 0;
void dfs(int u,int p =-1,int color = 0){
    if(color!=c[u])
        ans++,color = c[u];
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u,color);
    }
}

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n-1);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n-1;i++){
            graph[nums[i]-1].push_back(i+1);
            graph[i+1].push_back(nums[i]-1);
        }
        c.resize(n);
        for(auto &x:c)cin>>x;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}  
