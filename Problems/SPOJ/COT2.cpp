#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
typedef long long int lli;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> start(maxn);
vector<int> depth(maxn);
vector<int> End(maxn);
int idx;
int parent[25][maxn];
void dfs(int u,int p = -1,int d = 0){
    parent[0][u] = p;
    depth[u] = d;
    start[u] = idx++;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
    }
    End[u] = idx++;
}

int n;
void init(){
    for(int i = 0;i<n;i++)for(int j = 0;j<25;j++)parent[j][i] = -1;
    for(int i = 0;i<n;i++)depth[i]= -1;
    dfs(0);
    for(int i = 1;i<25;i++){
        for(int j  = 0;j<n;j++){
            if(parent[i-1][j]!=-1){
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }
    }
}

int LCA(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int diff = depth[u]-depth[v];
    for(int i = 24;i>=0;i--){
        if((diff>>i) &1)
            u = parent[i][u];
    }
    if(u == v)return u;
    for(int i = 24;i>=0;i--){
        if(parent[i][u]!= parent[i][v]){
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][v];
}

struct query{ 
    int l,r,id,lca;
    bool operator < (const query B){
        return r<B.r;
    }
};

int st[maxn];
vector<int> nodes(maxn);
vector<bool> vis(maxn);
int cont;
void add(int ind ,int val){
    if(vis[nodes[ind]] && --st[val] == 0)cont--;
    else if(!vis[nodes[ind]] && st[val]++ == 0)cont++;
    vis[nodes[ind]] = !vis[nodes[ind]];
}

int main(){__
    int u,v,m;
    cin>>n>>m;
    vector<int> values(n);
    for(auto &c:values)cin>>c;
    vector<int> copy = values;
    sort(copy.begin(),copy.end());
    int last = copy[0];
    vector<int> uniques;
    uniques.push_back(last);
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    for(int i = 0;i<n;i++){
        values[i] = lower_bound(uniques.begin(),uniques.end(),values[i])-uniques.begin();
    }
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    init(); 
    vector<lli> nums(idx);
    for(int i = 0;i<n;i++){
        nums[start[i]] = values[i];
        nums[End[i]] = values[i];
        nodes[start[i]] = i;
        nodes[End[i]] = i;
    }
    int block_size = ceil(sqrt(idx*1.0));
    vector<vector<query>> blocks((idx/block_size)+2,vector<query> ());
    vector<int> ans(m);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        if(start[u]>start[v])swap(u,v);
        int lca = LCA(u,v);

        if(lca== u){
            blocks[start[u]/block_size].push_back({start[u],start[v]+1,i,lca});
        }
        else{
            blocks[End[u]/block_size].push_back({End[u],start[v]+1,i,lca});
        }
    }
    for(int i = 0;i<blocks.size();i++){
        sort(blocks[i].begin(),blocks[i].end());
    }

    clock_t begin = clock();
    // for(int i = 0;i<idx;i++){
        // cout<<nums[i]<<" "<<nodes[i]<<endl;
    // }
    // cout<<endl;
    for(int i = 0;i<blocks.size();i++){
        int L,R;
        L = R = i*block_size;
        cont = 0;
        // cout<<"BLOCK: "<<i<<" "<<L<<" "<<R<<endl;
        for(auto q:blocks[i]){
            // cout<<q.l<<" "<<q.r<<" "<<q.lca<<" "<<q.id<<endl;
            while(R<q.r){
                add(R,nums[R]);
                R++;
            }
            while(L<q.l){
                add(L,nums[L]);
                L++;
            }
            while(L>q.l){
                L--;
                add(L,nums[L]);
            }   
            // cout<<cont<<" "<<nodes[q.l]<<" "<<nodes[q.r-1]<<" "<<start[q.lca]<<" "<<vis[q.lca]<<" "<<nodes[start[q.lca]]<<endl;
            if(q.lca!= nodes[q.l] && q.lca != nodes[q.r-1])
                add(start[q.lca],nums[start[q.lca]]);
            ans[q.id] = cont;
            if(q.lca!= nodes[q.l] && q.lca != nodes[q.r-1])
                add(start[q.lca],nums[start[q.lca]]);
            
        }   
        for(int j = L;j<R;j++){
            if(j>idx)break;
            add(j,nums[j]);
        }
        
    }
    for(auto c:ans)cout<<c<<endl;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(6)<<time_spent<<endl;
    return 0;
}