/**
 * Author: Alberto silva
 * Date: 2020-02-20
 * Source: Folklore
 * Description: Data structure for computing lowest common ancestors in a tree
 * (with 0 as root). C should be an adjacency list of the tree, either directed
 * or undirected.
 * Time: $O(N \log N + Q), O(1) per query$
 * Status: stress-tested
 */
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


