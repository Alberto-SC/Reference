#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
const int maxn = 200105;
const int mxlog = 25;
vector<int> graph[maxn];
vector<int> level[maxn];

vector<int> euler, first,height;
pair<int,int> ST[maxn][25];
int lg[maxn];

void dfs(int u, int h = 0,int p = -1) {
    first[u] = euler.size();
    height[u] = h;
    level[h].push_back(u);
    euler.push_back(u);
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, h + 1,u);
        euler.push_back(u);
    }
}

void build(vector<int> &A,int n){
    lg[1] = 0;
    for(int i = 2;i<maxn;i++)
        lg[i] = lg[i/2]+1;
    for(int i = 0;i<n;i++) 
        ST[i][0] = {height[A[i]],A[i]};
    for(int j = 1;j<25;j++)
        for(int i=0; i+(1<<j)<=n; i++)
            ST[i][j] = min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
}


void LCA(int n, int root = 0) {
    first.resize(n);
    height.resize(n);
    euler.reserve(n * 2);
    dfs(root);
    int m = euler.size();
    build(euler,m);
}


int query(int l, int r){
    int j = lg[r-l+1];
    return min(ST[l][j],ST[r-(1<<j)+1][j]).second;
}

int lca(int u, int v){
    int left = first[u], right = first[v];
    // cout<<left<<" "<<right<<endl;
    if (left > right)
        swap(left, right);
    return query(left, right);
}


int dist(int a,int b){
    return height[a]+height[b]-(2*height[lca(a,b)]);
}

signed main(){__
    int n,u,v,k;
    cin>>n>>k;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> ans;
    ans.push_back(1);
    LCA(n);
    set<int> poss;

    for(int i = 1;i<=k;i++){
        for(auto c:level[i]){
            poss.insert(c);
        }
        level[i].clear();
    }
    level[0].clear();
    while(poss.size()){
        auto it = poss.begin();
        ans.push_back(*it+1);
        for(int i = height[*it]+1;i<=min(n,height[*it]+k+1);i++){
            vector<int> nw;
            for(auto c:level[i]){
                if(dist(*it,c)<=k){
                    poss.insert(c);
                }
                else nw.push_back(c);
            }
            level[i] = nw;
        }
        poss.erase(it);
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
}

 
