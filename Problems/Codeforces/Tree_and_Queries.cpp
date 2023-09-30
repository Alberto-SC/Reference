#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> pos(maxn);
vector<int> last(maxn);
vector<int> colors;
struct query{
    int l,r,k,id;
};

int block;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
bool comp2(pair<int,int> A,pair<int,int> B){
    return pos[A.second]<pos[B.second];
}
bool comp(query x, query y){
    int aux = x.l/block;
    if (aux != y.l/block)
        return x.l < y.l;
    if(aux & 1)
		return x.r < y.r;
	return x.r > y.r;
}

int id = 0;
vector<int> c2;
void dfs(int u,int p = -1){
    pos[u] = id;
    c2.push_back(colors[u]);
    for(auto v:graph[u]){  
        if(v == p)continue;
        id++;
        dfs(v,u);
    }
    last[u] = id;
}
int total =0;
vector<int> buck(maxn);
vector<int> bit(maxn);


int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add_bit(int idx, int delta) {
    for (++idx; idx < maxn; idx += idx & -idx) bit[idx] += delta;
}

void add(int i){
    buck[c2[i]]++;
    int x = buck[c2[i]];
    add_bit(x,1);
    if(x != 1)
        add_bit(x-1,-1);
}
void rem(int i){
    buck[c2[i]]--;
    int x = buck[c2[i]];
    add_bit(x+1,-1);
    if(x!= 0)
        add_bit(x,1);
}

void printbit(){
    for(int i = 0;i<10;i++)
        cout<<sum(i,i)<<" ";
    cout<<endl;
}
int main(){__
    int n,m,u,v,k;
    cin>>n>>m;
    colors.resize(n);
    for(auto &c:colors)cin>>c;

    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    dfs(0);
    vector<query> q(m);
    block = sqrt(n);
    for(int i = 0;i<m;i++){
        cin>>u>>k;
        u--;
        q[i] = {pos[u],last[u],k,i};
    }
    sort(q.begin(),q.end(),comp);
    vector<int> ans(m);
    int l = 0, r = -1;
    // for(auto c:q)cout<<c.l<<" "<<c.r<<" "<<c.k<<endl;
    for (int i=0; i < m; i++){
        int L = q[i].l, R = q[i].r;
        while (l > L){
            l--;
            add(l);
        }
        while (r < R){
            r++;
            add(r);
        }
        while (l < L){
            rem(l);
            l++;
        }
        while (r > R){
            rem(r);
            r--;
        }
        ans[q[i].id] = sum(q[i].k,maxn-2);
    }
    for(auto c: ans)cout<<c<<endl;
    return 0;
}