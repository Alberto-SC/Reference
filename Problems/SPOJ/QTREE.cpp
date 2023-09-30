#include <bits/stdc++.h>
using namespace std;
const int maxn = 10007;
#define endl '\n'
#define x first
#define y second
vector<pair<int,int>> graph[maxn];
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
void add_edge(int u,int v,int c){
    graph[u].push_back({v,c});
    graph[v].push_back({u,c});
}
vector<int> p(maxn),head(maxn),stpos(maxn),lvl(maxn),sz(maxn),heavy(maxn,-1);
vector<int> st;
vector<int> lazy;
vector<int> val;

void update(int v,int sl, int sr,int pos,int val){
    if(sl == sr){
        st[v] = val;
        return ;
    }
    int mid = (sl+sr)>>1;
    if(pos<=mid)
        update(v<<1,sl,mid,pos,val);
    else
        update(v<<1|1,mid+1,sr,pos,val);
    st[v] = max(st[v<<1],st[v<<1|1]);
}

int query(int v ,int sl,int sr,int l,int r){
    if(l>sr || r<sl || sl>sr)return -10;
    if(sl>=l && sr<=r)
        return st[v];
    int mid = (sl+sr)>>1;
    return max(query(v<<1,sl,mid,l,r),query(v<<1|1,mid+1,sr,l,r));
}

int cn = 0;
void dfs(int u ,int pr = -1,int lev = 0){
    lvl[u] = lev;
    sz[u]= 1;
    int mx= 0;
    p[u] = pr;
    for(auto v:graph[u]){
        if(v.x == pr)continue;
        val[v.x] = v.y;
        dfs(v.x,u,lev+1);
        if(sz[v.x]>mx){
            mx = sz[v.x];
            heavy[u] = v.x;
        }
        sz[u]+=sz[v.x];
    }
}

void HLD(int u,int ch,int n){
    head[u] = ch;
    stpos[u] = cn++;
    for(int i=0, currpos = 0; i < n; ++i)
		if(p[i] == -1 || heavy[p[i]] != i)
			for(int j = i; j != -1; j = heavy[j])
			{
				head[j] = i;
				stpos[j] = currpos;
				currpos++;
            }
} 

int query(int a,int b,int n){
    int res = 0;
    while(head[a]!= head[b]){
        if(lvl[head[a]]< lvl[head[b]])
            swap(a,b);
        res = max(res,query(1,0,n-1,stpos[head[a]],stpos[a]));
        a = p[head[a]];
    }
    if(lvl[a]> lvl[b])
        swap(a,b);
    // if weigths are in nodes quit if
    if(stpos[a]+1<=stpos[b])
        res=max(res,query(1,0,n-1,stpos[a]+1,stpos[b]));
    return res;
}

  
int main(){__
    int n,u,t,v,q,c;
    cin>>t;
    while(t--){
        cn = 0;
        cin>>n;
        lazy.assign(4*n,0);
        st.assign(4*n,0);
        val.assign(maxn,-1);
        heavy.assign(2*n,-1);
        for(int i = 0;i<n;i++)graph[i].clear();
        vector<pair<int,int>> edges;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v>>c;
            u--,v--;
            edges.push_back({u,v});
            add_edge(u,v,c);
        }
        dfs(0);
        HLD(0,0,n);
        update(1,0,n-1,0,-100);       
        for(int i = 1;i<n;i++)
            update(1,0,n-1,stpos[i],val[i]);       
        string type;
        while(1){
            cin>>type;
            if(type == "DONE")break;
            if(type == "QUERY"){
                cin>>u>>v;
                u--,v--;
                cout<<query(u,v,n)<<endl;
            }
            else {
                int idx,val;
                cin>>idx>>val;
                idx--;
                u = edges[idx].first;
                v = edges[idx].second;
                // cout<<u<<" "<<v<<endl;
                // cout<<lvl[u]<<" "<<lvl[v]<<endl;
                if(lvl[u]<lvl[v])swap(u,v);
                // cout<<u<<endl;
                update(1,0,n-1,stpos[u],val);
            }
        }
    }
    return 0;
}