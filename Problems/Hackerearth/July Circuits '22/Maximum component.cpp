#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 400007;
vector<int> bit[2];

void add(int idx,int val,int who){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[who][idx]+=val;
}

int sum(int idx,int who){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[who][idx];
    return res;
}

int sum(int l,int r,int who){
    return sum(r,who)-sum(l-1,who);
}

vector<int> sz;
vector<int> P;

int root(int u){
    return P[u]==u?u:P[u] = root(P[u]);
}

int unionBySize(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return false;
    if(sz[u]<sz[v])swap(u,v);
    add(sz[u],-1,0);
    add(sz[u],-sz[u],1);
    add(sz[v],-1,0);
    add(sz[v],-sz[v],1);
    sz[u]+= sz[v];
    add(sz[u],1,0);
    add(sz[u],sz[u],1);
    P[v] = u;
    return true;
}

void print(int n){
    for(int i = 0;i<=n;i++){
        cout<<sum(i,i,0)<<" ";
    }
    cout<<endl;
    for(int i = 0;i<=n;i++){
        cout<<sum(i,i,1)<<" ";
    }
    cout<<endl;
}

signed main(){__
	int t= 1,n,u,v,k,type,q;
    cin>>n>>q;
    bit[0].resize(maxn);
    bit[1].resize(maxn);
    sz.resize(maxn,1);
    P.resize(maxn);
    iota(P.begin(),P.end(),0);
    add(1,n,0);
    add(1,n,1);
    // print(n);
    while(q--){
        cin>>type;
        if(type ==1){
            cin>>u>>v;
            u--,v--;
            unionBySize(u,v);
        }
        else{
            cin>>k;
            int l = 0,r = n+1;
            while(l+1<r){
                int m = (l+r)>>1;
                if(sum(m,n,0)>=k+1)
                    l = m;
                else 
                    r = m;
            }
            if(l == 0){
                cout<<n+1<<endl;
                continue;
            }
            int x = sum(l+1,n,1);
            int y = sum(l+1,n,0);
            k-=(y-1);
            // cout<<l<<" "<<x<<" "<<y<<" "<<k<<endl;

            int ans = x+(k*l);
            cout<<ans<<endl;
        }
        // print(n);
    }
    return 0;
}  
