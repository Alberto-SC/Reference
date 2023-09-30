#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph(maxn);
vector<int> graph2[maxn];
vector<bool> vis(maxn);
vector<int> dis(maxn);
int n;
const int inf = 1e9+7;
vector<int> parent(maxn,-1);
int q[maxn*10];
int bfs(int s,bool rev){
    dis.assign(n+1,inf);
    dis[s] = 0;
    int top = 0;
    q[top++] = s;
    for(int i = 0;i<top;i++){
        int u = q[i],v;
        if(rev){
            for(auto v:graph2[u]){
                if(vis[v]|| dis[v]<dis[u]+1)continue;
                dis[v] = dis[u]+1;
                q[top++] = v;
                parent[v] = u;
            }
        }
        else{
            v = graph[u];
            if(vis[v]|| dis[v]<dis[u]+1)continue;
            dis[v] = dis[u]+1;
            q[top++] = v;
        } 
    }
    int mx = -1,leaf;
    for(int i = 0;i<=n;i++){
        if(dis[i]>mx && dis[i]!= inf)
            leaf = i,mx = dis[i];
    }
    return leaf;
}
signed main(){__
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 1;i<=n;i++){
            graph[i] = nums[i-1];
            vis[i] = false;
            graph2[nums[i-1]].push_back(i);
        }

        vector<bool> used(n+1);
        vector<int> ans(n+1);
        pair<int,int> ciclo = {-1,-1};
        pair<int,int> ciclo2;
        vector<int> order(n);
        iota(order.begin(),order.end(),1);
        sort(order.begin(),order.end(),[&](int a,int b){
            return graph2[a].size()>graph2[b].size();
        });
        for(int j = 0;j<n;j++){
            int i = order[j];
            if(vis[i])continue;
            int leaf = bfs(i,0);
            if(leaf ==i)continue;
            int leaf2 = bfs(leaf,1);
            int first = leaf2;
            while(leaf2!=leaf){
                used[leaf2] = true;
                vis[leaf2] = true;
                ans[leaf2] = parent[leaf2];
                leaf2 = parent[leaf2];
            }
            vis[leaf] = true;
            ans[leaf] = first;
            if(nums[leaf-1]!=first)
                ciclo = {leaf,first};
            ciclo2= {leaf,first};
            used[leaf]= true;
        }
        vector<int> faltan;
        for(int i = 1;i<=n;i++){
            if(ans[i]==0)
                faltan.push_back(i);
        }
        if(faltan.size()==1){
            if(ciclo.first==-1){
                if(nums[faltan[0]-1]==ciclo2.first){
                    ans[ciclo2.second] = faltan[0];
                    ans[faltan[0]] = ciclo2.first;
                    ans[ciclo2.first] = ciclo2.second;
                }
                else{
                    ans[ciclo2.first] = faltan[0];
                    ans[faltan[0]] = ciclo2.second;
                    ans[ciclo2.second] = ciclo2.first;
                }
            }
            else{
                if(nums[faltan[0]-1]==ciclo.first){
                    ans[ciclo.second] = faltan[0];
                    ans[faltan[0]] = ciclo.first;
                    ans[ciclo.first] = ciclo.second;
                }
                else{
                    ans[ciclo.first] = faltan[0];
                    ans[faltan[0]] = ciclo.second;
                    ans[ciclo.second] = ciclo.first;
                }
            }
        }
        else{
            for(int i =0;i<faltan.size();i++){
                ans[faltan[i]]= faltan[(i+1)%faltan.size()];
                // ans[faltan[(i+1)%faltan.size()]]= faltan[i];
            }
        }
        int cont = 0;
        for(int i = 1;i<=n;i++)
            if(ans[i]==nums[i-1])cont++;
        cout<<cont<<endl;
        for(int i = 1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;

    }
    return 0;
}  
