#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 100007;
vector<int> graph[maxn];
struct ordered_multiset { // multiset supporting duplicating values in set
    int len = 0;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    unordered_map<int, int> mp; // hash = 96814
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

    ordered_multiset() { len = 0; T.clear(), mp.clear(); }

    inline void insert(int x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c); }

    inline void erase(int x){
        x += MAXVAL;
        int c = mp[x];
        if(c) {
            c--, mp[x]--, len--;
            T.erase((x*ADD) + c); } }

    inline int kth(int k){        // 1-based index,  returns the
        if(k<1 || k>len) return -1;     // K'th element in the treap,
        auto it = T.find_by_order(--k); // -1 if none exists
        return ((*it)/ADD) - MAXVAL; } 

    inline int lower_bound(int x){      // Count of value <x in treap
        x += MAXVAL;
        int c = mp[x];
        return (T.order_of_key((x*ADD)+c)); }

    inline int upper_bound(int x){      // Count of value <=x in treap
        x += MAXVAL;
        int c = mp[x];
        return (T.order_of_key((x*ADD)+c)); }

    inline int size() { return len; }   // Number of elements in treap
};

vector<ordered_multiset> dist;
int mx,mn;
int z[2] = {0,0};
void dfs(int u,int p = -1){
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u);
        for(auto c:dist[v].T){
            z[0]+= dist[u].len-lower_bound(mx-c+1);
        }
        for(auto c:dist[v].T){
            z[1]+= dist[u].len-lower_bound(mn-c+1);
        }
        // count(dist[v],u,mn,0);
        // count(dist[v],u,mx+1,1);
        if(dis[v].len>dist[u].len){
            for(auto c:dist[u].T){
                dist[v].insert(c+1);
            }
            dist[u] = v;
        }
        else{
            for(auto c:dist[v].T){
                dist[u].insert(c+1);
            }
        }
    }
}
int main(){__
    freopen("awesome.in", "r", stdin);
	int t= 1,n,l,r,u,v;
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        dist.resize(n);
        for(int i = 0;i<n;i++){
            graph[i].clear();
            // dist.clear();
            // insert(0,i);
        }
        for(int i = 0;i<n;i++)
            dist[i].insert(0);

        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        mn = (n-1)-r;
        mx = (n-1)-l;
        z[0] = 0;
        z[1] = 0;
        dfs(0);
        cout<<z[0]-z[1]<<endl;
    }
    return 0;
}
