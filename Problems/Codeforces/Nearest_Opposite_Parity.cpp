#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
vector<int> graph[maxn];

vector<int> distimp(maxn,-1);
vector<int> distpar(maxn,-1);
vector<int> nums;

const int INF = 100000007;

void add_edge(int u,int v){
    graph[v].push_back(u);
}

int q[maxn];
int topQ;
void bfs(vector<int>  &A,bool who){
    topQ = 0;
    if(who)
        for(int i = 0;i<maxn;i++)distimp[i] = INF;
    else
        for(int i = 0;i<maxn;i++)distpar[i] = INF;
    for (int x : A){
        if(who)
            distimp[x] = 0;
        else distpar[x] = 0;
        q[topQ++] = x;
    }
    for (int i=0;i<topQ;i++){
        int u = q[i];
        for (int v: graph[u]) {
            if(who){
                if (distimp[v] <= distimp[u] + 1) continue;
                distimp[v] = distimp[u] + 1;
                q[topQ++] = v;
            }
            else {
                if (distpar[v] <= distpar[u] + 1) continue;
                distpar[v] = distpar[u] + 1;
                q[topQ++] = v;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    vector<int> odds;
    vector<int> evens;
    for(int i = 0;i<n;i++){
        if(i+nums[i]<n)
            add_edge(i,i+nums[i]);
        if(i-nums[i]>=0)    
            add_edge(i,i-nums[i]);
        if(nums[i]&1)odds.push_back(i);
        else evens.push_back(i);
    }
    bfs(odds,1);
    bfs(evens,0);
    vector<int> ans(n);
    for(int i = 0;i<n;i++){ 
        if(nums[i]&1)distpar[i]==INF?ans[i]=-1:ans[i] = distpar[i];
        else distimp[i]==INF?ans[i] = -1:ans[i] = distimp[i];
    }
    for(int i = 0;i<n;i++){
        if(ans[i]== -1){
            int ans1 = -1,ans2 = -1;
            if(i+nums[i]< n && ans[i+nums[i]]!= -1)
                ans1 = ans[i+nums[i]];
            if(i-nums[i]>=0 && ans[i-nums[i]]!= -1)
                ans2 = ans[i-nums[i]];

            if(ans1 != -1 && ans2 != -1)ans[i] = min(ans1+1,ans2+1);
            else if(ans1 != -1)ans[i] = ans1+1;
            else if(ans2 != -1)ans[i] = ans2+1;
        }
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}

