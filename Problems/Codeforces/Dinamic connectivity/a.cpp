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
void solve(int l, int r) {
    if(l == r) {
        if(op[l] == '?') cout<<ans<<endl;
        return; 
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

signed main() {
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++) 
        p[i] = i, sz[i] = 1; 

    if(!k) return 0;

    for(int i = 1; i <= k; i++) {
        cin>>op[i];
        if(op[i] == '?') continue; 
        cin>>u[i]>>v[i];
        if(u[i] > v[i]) 
            swap(u[i], v[i]); 

        pair<int,int> x(u[i], v[i]); 
        if(mp.count(x)) {
            o[i] = mp[x]; 
            o[o[i]] = i; 
            mp.erase(x); 
        } else {
            mp[x] = i; 
        }
    }
    int idx = k; 
    for(auto it : mp) {
        o[it.second] = ++idx; 
        o[idx] = it.second; 
        op[idx] = '-';
        tie(u[idx], v[idx]) = it.first; 
    }
    ans = n; 
    solve(1, idx); 
}