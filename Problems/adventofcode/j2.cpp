#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<int> graph[1000];
lli cont = 0;
int lst = 0;
vector<lli> DP(1000,-1);
lli dfs(int u,int p = -1){
    // if(DP[u]!= -1)return DP[u];
    if(u == lst)return DP[u] = 1;
    lli ans = 0;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u);
        ans+= DP[v];
    }
    return DP[u] = ans;
}

int main(){
    string s;
    vector<lli> nums;
    lli x;
    while(cin>>x){
        nums.push_back(x);
    }
    vector<bool> b(100000); 
    for(int i= 0;i<nums.size();i++){
        b[nums[i]] = true;
    }

    int cont1 = 0,cont2 =0 ,cont3 = 0;
    nums.push_back(0);
    sort(nums.begin(),nums.end());
    lst = nums.back();
    for(int i = 0;i<nums.size();i++){
        // cout<<nums[i]<<" ";
        if(b[nums[i]+1])graph[nums[i]].push_back(nums[i]+1);
        if(b[nums[i]+2])graph[nums[i]].push_back(nums[i]+2);
        if(b[nums[i]+3])graph[nums[i]].push_back(nums[i]+3);
    }
    cout<<dfs(0)<<endl;
    // cout<<cont<<endl;
    return 0;
}