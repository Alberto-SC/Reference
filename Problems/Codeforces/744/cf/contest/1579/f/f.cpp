#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1000007;
vector<int> graph(maxn);
int top;
vector<int> q(maxn*5);
vector<int> dis(maxn);
const int inf = 1e15;
void bfs(int n,vector<int> &s){
    for(int i = 0;i<n;i++)
        dis[i] = inf;
    
    for(int i = 0;i<s.size();i++){
        dis[s[i]] = 0;
        q[top++] = s[i];
    }
    for(int i = 0;i<top;i++){
        int u = q[i];
        int v = graph[u];
        if(dis[v]<dis[u]+1)continue;
        dis[v] =dis[u]+1;
        q[top++] = v; 
    }
}

signed main(){__
	int t= 1,n,d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<bool> vis(n);
        vector<int> mn(n,1e15);
        vector<int> s;
        for(int i = 0;i<n;i++){
            if(nums[i]== 0)s.push_back(i);
            int next = i-d;
            if(next<0)next+=n;
            graph[i]=next;
        }
        top = 0;
        bfs(n,s);
        int mx = 0;
        for(int i = 0;i<n;i++){
            mx =max(mx,dis[i]);   
        }
        if(mx == 1e15)cout<<-1<<endl;
        else cout<<mx<<endl;
    }
    return 0;
}  
