#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007;
vector<pair<int,set<int>>> graph;
vector<int> graph2[maxn];
vector<set<int>> graph3;
#define x first 
#define y second
bool flag = true;
vector<int> ans;
void dfs(int u,int color){
    ans[u] = color;
    for(auto v:graph2[u]){
        if(ans[v]==color){
            flag = false;
            return ;
        }
        if(ans[v]==-1)
            dfs(v,color^1);
    }
}
signed main(){__
	int t= 1,n,m,u,v;
    while(t--){
        cin>>n>>m;
        graph.resize(n);
        graph3.resize(n);
        set<int> zero;
        for(int i = 0;i<n;i++)
            graph[i] = {i,zero};
        
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].y.insert(v);
            graph[v].y.insert(u);
            graph3[u].insert(v);
            graph3[v].insert(u);
        }
        sort(graph.begin(),graph.end(),[&](pair<int,set<int>> A ,pair<int,set<int>> B){
            return A.second.size()<B.second.size();
        });
        ans.resize(n,3);
        for(int i = 0;i<n;i++){
            if(graph[0].y.count(i))
                ans[i] = -1;
        }
        for(int i = 1;i<n;i++){
            if(ans[graph[i].x]!=-1)continue;
            for(auto c:graph[i].y){
                if(ans[c]!=-1)continue;
                else {
                    graph2[graph[i].x].push_back(c);
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(ans[i]==-1){
                dfs(i,0);
                break;
            }
        }
        if(!flag)return cout<<-1<<endl,0;
        for(int i = 0;i<n;i++)
            if(ans[i]==-1)
                return cout<<-1<<endl,0;
        
        set<int> v1;
        set<int> v2;
        set<int> v3;
        for(int i = 0;i<n;i++)
            if(ans[i]!=3)ans[i]++;
        
        for(int i = 0;i<n;i++){
            if(ans[i]==1)
                v1.insert(i);
            else if(ans[i]==2)
                v2.insert(i);
            else 
                v3.insert(i);
        }
        for(int i = 0;i<n;i++){
            if(ans[graph[i].x]==1){
                // cout<<graph[i].x<<" "<<graph3[graph[i].x].size()<<" "<<v1.size()<<endl;
                if(graph3[graph[i].x].size()!= n-v1.size())
                    flag = false;
            }
            if(ans[graph[i].x]==2){
                // cout<<graph[i].x<<" "<<graph3[graph[i].x].size()<<" "<<v2.size()<<endl;
                if(graph3[graph[i].x].size()!= n-v2.size())
                    flag = false;
            }
            if(ans[graph[i].x]==3){
                // cout<<graph[i].x<<" "<<graph3[graph[i].x].size()<<" "<<v3.size()<<endl;
                if(graph3[graph[i].x].size()!= n-v3.size())
                    flag = false;
            }
        }
        if(!flag)cout<<"-1"<<endl;
        else {
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}  
