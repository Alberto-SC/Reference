#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
vector<int> graph[maxn];
typedef long long int lli;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<lli> sub(maxn,0);
vector<int> dist(maxn,0);
vector<int> brach(maxn,0);
vector<int> nums;
vector<lli> sum(maxn,0);
lli res = 0;
void dfs(int v, int p = -1, int h = 0) {
	res += h * 1ll * nums[v];
	sum[v] = nums[v];
	for (auto to : graph[v]) {
		if (to == p) continue;
		dfs(to, v, h + 1);
		sum[v] += sum[to];
	}
}
lli mx = -1;
void dfs2(int u,int p = -1){
    mx = max(mx,res);
    for(auto v:graph[u]){
        if(v == p)continue;
        res-=sum[v];
        sum[u]-=sum[v];
        res+=sum[u];
        sum[v]+=sum[u];
        dfs2(v,u);
        sum[v]-=sum[u];
        res-=sum[u];
        sum[u]+=sum[v];
        res+=sum[v];
    }   
}

int main(){
    int n,u,v;
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    dfs(0);
    // for(int i = 0;i<n;i++)cout<<sum[i]<<" ";
    // cout<<endl;
    dfs2(0);
    cout<<mx<<endl;
    return 0;
}