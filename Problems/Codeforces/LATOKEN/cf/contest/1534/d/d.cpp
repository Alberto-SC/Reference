#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 2007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
void dfs(int u,int p =-1){
    vis[u] = true;
    if(p!=-1)cout<<u<<" "<<p<<endl;
    for(auto v:graph[u]){
        if(vis[v])continue;
        dfs(v,u);
    }
}

void dfs2(int u){
    vis[u] = true;
    for(auto v:graph[u]){
        if(vis[v])continue;
        dfs2(v);
    }
}
signed main(){
	int t= 1,n;
    cin>>n;
    queue<int> q;
    q.push(1);
    vector<int> ans(n);
    vector<bool> used(n+1);
    used[1] = true;
    vector<int> dists[n+1];
    int mx = (n+1)/2;
    int cont = 0;
    while(!q.empty()){
        int current = q.front();
        cont++;
        cout<<"? " <<current<<endl;
        q.pop();
        for(auto &c:ans)cin>>c;
        int cont1 = 0,cont2 = 0;
        for(int i = 0;i<n;i++){
            if(ans[i]==1){
                graph[current].push_back(i+1);
                graph[i+1].push_back(current);
                if(!used[i+1])
                    cont1++;
            }
            if(ans[i]==2 &&!used[i+1]){
                cont2++;
            }
        }
        for(int i = 0;i<n;i++){
            if(cont1>=cont2){
                if(ans[i]==2 &&!used[i+1]){
                    cont2++;
                    q.push(i+1);
                    used[i+1] = true;
                }                
            }
            else {
                if(ans[i]==1 &&!used[i+1]){
                    cont2++;
                    q.push(i+1);
                    used[i+1] = true;
                }                
            }
        }
        dists[current] = ans;
        vis.assign(n,false);
        dfs2(1);
        bool flag = true;
        for(int i = 1;i<=n;i++){
            if(!vis[i])flag = false;
        }
        if(flag|| cont==mx)break;
    }
    cout<<"!"<<endl;
    vis.assign(n,false);
    dfs(1);
    return 0;
}  

// 1-> 0 1 1 1 2 3 3 1 2 3 2 2 3 4 4
// 5-> 2 3 3 1 0 1 1 3 4 5 4 4 5 6 6
// 9-> 2 3 3 3 4 5 5 1 0 1 4 4 5 6 6
// 11-> 2 1 3 3 4 5 5 3 4 5 0 2 3 4 4
// 12-> 2 1 3 3 4 5 5 3 4 5 2 0 1 2 2
// 14-> 4 3 5 5 6 7 7 5 6 7 4 2 1 0 2
// 15-> 4 3 5 5 6 7 7 5 6 7 4 2 1 2 0