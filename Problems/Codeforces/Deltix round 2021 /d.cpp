#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1007;
vector<int> p(maxn);
vector<int> sz(maxn);
vector<int> graph[maxn];

int root(int u){
    return p[u] ==u?u:p[u]= root(p[u]);
}

bool union_by_size(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return false;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    return true;
}

signed main(){__
    int T = 1,n,d;
    cin>>n>>d;
    vector<int> f(n+1);

    for(int i = 0;i<d;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        
        f[x]++;
        f[y]++;
        
        
        vector<int> v(n);
        iota(p.begin(),p.end(),0);
        iota(v.begin(),v.end(),1);
        sz.assign(n+1,1);

        sort(v.begin(),v.end(),[&](int a,int b){
            return f[a]>f[b];
        });

        int rem = i+1;
        for(auto c:v){
            for(auto u:graph[c]){
                if(union_by_size(c,u)){
                    rem--;
                }
            }
        }

        vector<int> mxz;
        for(int j = 1;j<=n;j++){
            if(root(j)== j){
                mxz.push_back(sz[j]);
            }
        }
        sort(mxz.rbegin(),mxz.rend());
        int ans = mxz[0]-1;
        for(int i = 1;i<=rem;i++){
            ans+=mxz[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}