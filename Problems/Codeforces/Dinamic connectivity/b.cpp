#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 3e5 + 7; 

int p[N], sz[N], ans; 
stack<int> st; 

int n, k, u[N << 1], v[N << 1], o[N << 1];
char op[N << 1]; 
map<pair<int,int>, int> mp; 

int find(int u) {
    while(p[u] != u) u = p[u]; // Notice: No path compression. Path Compression will make the algorithm O(n^2) 
    return u; 
}
void Union(int u, int v) {
    u = find(u); v = find(v); 
    if(u == v) return; 
    if(sz[u] > sz[v]) swap(u, v); 
    p[u] = v; 
    sz[v] += sz[u];
    ans--; 
    st.push(u); 
}
void rollbax(int t) { 
    while(st.size() > t) {
        int u = st.top(); st.pop(); 
        sz[p[u]] -= sz[u]; 
        p[u] = u; ans++;
    }
}
vector<int> res(N);
void solve(int l, int r) {
    if(l == r) {
        res[i] = ans;
    } 
    int m = l + r >> 1, now = st.size(); 
     
    for(int i = m + 1; i <= r; i++) 
        if(o[i] < l) Union(u[i], v[i]); 
    solve(l, m); 
    rollbax(now); 
    
    for(int i = l; i <= m; i++) 
        if(o[i] > r) Union(u[i], v[i]);
    solve(m + 1, r); 
    rollbax(now); 
}

vector<int> graphjj

signed main() {
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++) 
        p[i] = i, sz[i] = 1; 

    ans = n;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    int idx = k; 
    for(int i = 1; i <= k; i++) {
        cin>>u[i]>>v[i];
        if(u[i] > v[i]) 
            swap(u[i], v[i]); 

        pair<int,int> x(u[i], v[i]); 
        o[i] = ++idx;
        o[idx] = i; 
    }
    for(auto it : mp) {
        o[it.second] = ++idx; 
        o[idx] = it.second; 
        op[idx] = '-';
        tie(u[idx], v[idx]) = it.first; 
    }
    int last = ans;
    solve(1, idx); 
    int bridges = 0;
    for(int i = 1;i<=k;i++){
        if(res[i]==)    
    } 
}