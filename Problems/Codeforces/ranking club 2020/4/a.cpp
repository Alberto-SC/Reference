#include<bits/stdc++.h> 
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> nums2;
vector<int> nums;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void dfs(int u ,int p){
    int ans = 0,gc = nums[u];
    for(auto c:graph[u]){
        if(c == p)continue;
        dfs(c,u);
    }

}
int main(){
    int n;
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
        add_edge(u,v);
    }
    dfs(0);
    int k = 2;
    int mx=0;
    for(int i=0;i<n;i++){
        int ans=0;
        int gc=nums2[i];
        int j;
        for(j=i+1;j<n;j++){
            gc=__gcd(gc,nums2[j]);
            if(gc<k)
            break;
        }
        if(j>i+1)
            ans=j-i;
        if(ans>mx)
            mx=ans;
            if(mx>=n-i)
                break;
    }
    cout<<mx<<endl;
    return 0;
}