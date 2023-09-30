#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
const int mod = 1e9+7;
vector<int> graph[maxn];
vector<int> gt[maxn];
int parent[25][maxn];
vector<int> depth(maxn);

void dfs(int u,int p = -1,int d = 0){
    depth[u] = d;
    parent[0][u] = p;
    if(p!=-1)gt[u].push_back(p);
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u,d+1);
    }
}

void build(int n){
    for(int i = 0;i<n;i++)for(int j = 0;j<25;j++)parent[j][i] = -1;
    for(int i = 0;i<n;i++)depth[i] =-1;
    dfs(0);
    for(int i = 1;i<25;i++){
        for(int j = 0;j<n;j++){
            if(parent[i-1][j]!= -1)
                parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);

    int diff = depth[u]-depth[v];
    for(int i = 24;i>=0;i--){
        if((diff>>i)&1)
            u = parent[i][u];
    }
    if(u ==v)return v;

    for(int i = 24;i>=0;i--){
        if(parent[i][u] != parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

set<int> st;

void dfs2(int u,int last,int p = -1){
    st.insert(u);
    if(u ==last)return ;
    for(auto v:gt[u]){
        dfs2(v,last,u);
    }
}

signed main(){__
    int t,n,u,v,s;    
    cin>>t;
    while(t--){
        cin>>n>>s;
        for(int i = 0;i<n;i++){
            gt[i].clear();
            graph[i].clear();
        }
        vector<int> a(n),b(n);
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        for(int i = 0;i<n;i++)
            cin>>a[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];

        build(n);
        int cont = 0;
        map<vector<vector<int>>,int> mp;
        for(int mask = 0;mask<(pow(n,n));mask++){
            int aux = mask;
            vector<int> assign;
            while(aux){
                assign.push_back(aux%n);
                aux/=n;
            }
            while(assign.size()!=n)assign.push_back(0);

            // cout<<" -> "<<endl;
            vector<int> paths[n];
            for(int i = 0;i<n;i++)
                paths[assign[i]].push_back(i);
            
            bool valid = true;
            
            // for(auto c:assign)cout<<c<<"  ,  ";
            // cout<<endl;
            vector<vector<int>> partition;
            // vector<int> seen = {0,1,0,0};
            for(int i = 0;i<n;i++){
                if(paths[i].size()==0)continue;
                sort(paths[i].begin(),paths[i].end(),[&](int a,int b){
                     return depth[a]<depth[b];
                });
                int sum = 0;
                for(int j = 0;j<paths[i].size();j++){
                    sum+=a[paths[i][j]];
                    sum-=b[paths[i][j]];
                }
                // for(auto c:paths[i])cout<<c<<" ";
                // cout<<endl;
                for(auto c:paths[i]){
                    for(auto d:paths[i]){
                        int LCA = lca(c,d);
                        // if(assign==seen)
                        // cout<<c<<" "<<d<<" "<<LCA<<endl;
                        if(LCA!= c && LCA != d)
                            valid = false;
                    }
                }
                if(sum!=0)valid = false;
                if(!valid)break;      
            }
            if(valid){
                for(int i = 0;i<n;i++){
                    if(paths[i].size()==0)continue;
                    sort(paths[i].begin(),paths[i].end());
                    partition.push_back(paths[i]);
                }
                sort(partition.begin(),partition.end(),[&](vector<int> a,vector<int> b){
                    return a[0]<b[0];
                });
                if(mp.count(partition)==0){
                    for(int i =0;i<n;i++){
                        if(paths[i].size()==0)continue;
                        st.clear();
                        vector<int> copy = paths[i];
                        sort(copy.begin(),copy.end(),[&](int a,int b){
                            return depth[a]<depth[b];
                        });
                        dfs2(copy.back(),copy[0]);
                        // for(auto c:st)cout<<c<<" ";
                        // cout<<endl;
                        for(int j = 0;j<paths[i].size();j++){
                            if(st.count(paths[i][j])==0){
                                valid = false;
                                break;
                            }
                            else st.erase(paths[i][j]);
                        }
                        if(st.size())
                            valid = false;
                    }
                    if(valid){ 
                        // for(auto c:assign)cout<<c+1<<" ";
                        // cout<<" -> YES"<<endl;
                        cont++;
                        // break;
                        mp[partition]++;
                    }
                }
            }
            // else 
                // cout<<" -> NO"<<endl;
        }
        cout<<cont<<endl;

    }
    return 0;
}
