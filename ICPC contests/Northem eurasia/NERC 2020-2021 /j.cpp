#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
#define x first
#define y second
vector<int> sz(maxn,1);
vector<int> p(maxn,0);
int root(int u){
    return u == p[u]?u:p[u] = root(p[u]);
}

bool unioin_by_sz(int u,int v){
    u = root(u);
    v = root(v);
    if(u ==v)return false;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v]= u;
    return true;
}

struct edge{
    int u,v,c;
    bool operator <(const edge B){
        return c<B.c;
    }
};

vector<pair<int,int>> graph[maxn];
vector<int> parent(maxn),head(maxn),stpos(maxn),lvl(maxn),sizes(maxn);
vector<int> st;
vector<int> lazy;
vector<int> heavy(maxn,-1),val(maxn);
int n; 
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
    st[v] += lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}
void updateST(int l,int r,int val,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    updateST(l,r,val,v<<1,sl,m);
    updateST(l,r,val,v<<1|1,m+1,sr);
    st[v] = max(st[v<<1],st[v<<1|1]);
}

int queryST(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return max(queryST(l,r,v<<1,sl,m),queryST(l,r,v<<1|1,m+1,sr));
}

void dfs(int u ,int pr = -1,int lev = 0){
    lvl[u] = lev;
    sizes[u]= 1;
    int mx= 0;
    parent[u] = pr;
    for(auto v:graph[u]){
        if(v.x == pr)continue;
        val[v.x] = v.y;
        dfs(v.x,u,lev+1);
        if(sizes[v.x]>mx){
            mx = sizes[v.x];
            heavy[u] = v.x;
        }
        sizes[u]+=sizes[v.x];
    }
}

void HLD(int u){
    for(int i=0, pos = 0; i<n; i++)
		if(parent[i] == -1 || heavy[parent[i]] != i)
			for(int j = i; j != -1; j = heavy[j]){
				head[j] = i;
				stpos[j] = pos;
				pos++;
            }
} 


int query(int a,int b){
    int res = 0;
    while(head[a]!= head[b]){
        if(lvl[head[a]]< lvl[head[b]])
            swap(a,b);
        res = max(res,queryST(stpos[head[a]],stpos[a]));
        a = parent[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    res= max(res,queryST(stpos[a]+1,stpos[b]));
    return res;
}

int main(){__
	int t= 1,u,v,c,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        st.assign(4*n,0);
        lazy.assign(4*n,0);
        for(int i = 0;i<n;i++)
            p[i] = i,sz[i] = 1,graph[i].clear(),heavy[i] =-1;
        vector<edge> edges;
        vector<bool> used(m);
        int mn  = 1e9+7;
        int idx = 0;
        for(int i = 0;i<m;i++){
            cin>>u>>v>>c;
            u--,v--;
            edges.push_back({u,v,c});
        }
        sort(edges.begin(),edges.end());        
        for(int i = 0;i<m;i++){
            u = edges[i].u;
            v = edges[i].v;
            c = edges[i].c;
            if(unioin_by_sz(u,v))
                used[i] = true;
        }   
        lli ans1 = 0;
        int mx = 0;
        bool flag = false;
        for(int i = 0;i<m;i++){
            u = edges[i].u;
            v = edges[i].v;
            c = edges[i].c;
            if(used[i]){
                graph[u].push_back({v,c});
                graph[v].push_back({u,c});
                mx = max(mx,c);
                if(edges[i].c>k){
                    ans1+=edges[i].c-k;
                    flag = true;
                }
            }
        }
        if(!flag)
            ans1 = k-mx;
        dfs(0);
        HLD(0);
        for(int i = 0;i<n;i++)
            updateST(stpos[i],stpos[i],val[i]);
        
        lli res = ans1;
        for(int i = 0;i<m;i++){
            if(!used[i]){
                u = edges[i].u;
                v = edges[i].v;
                c = edges[i].c;
                if(!flag && c<mx)continue;
                lli ans;
                if(flag)
                    ans = ans1;
                else
                    ans = 0;
                lli mxc =  query(u,v);
                if(mxc>k)ans-= k-mxc;
                ans+=abs(c-k);
                res = min(res,ans);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}  

