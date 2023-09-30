#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 998244353;
vector<int> p;
vector<int> sz;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }   
    return x;
}

int parent(int u){
    return u==p[u]? u:p[u] = parent(p[u]);
}

void union_sz(int u,int v){
    u = parent(u);
    v = parent(v);
    if(u ==v)return ;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
}

signed main(){__
	int t= 1,n,C,N,M,x;
    cin>>t;
    while(t--){
        cin>>C>>N>>M;
        p.assign(C,0);
        sz.assign(C,1);
        iota(p.begin(),p.end(),0);
        vector<int> s[N];
        for(int i = 0;i<C;i++){
            cin>>x;
            int l,r;
            for(int j = 0;j<2*x;j++){
                if(j%2==0)cin>>l;
                else {
                    cin>>r;
                    l--,r--;
                    for(int k = l;k<=r;k++){
                        s[k].push_back(i);
                    }
                }
            }
        }
        for(int i = 0;i<N;i++){
            for(int j = 1;j<s[i].size();j++)
                union_sz(s[i][j],s[i][j-1]);
        }
        int cont = 0;
        set<int> st;
        for(int i = 0;i<N;i++){
            if(s[i].size()==0){
                cont++;
            }
            else {
                st.insert(parent(p[s[i][0]]));
            }
        }

        cont+=st.size();
        cout<<mod_pow(M,cont)<<endl;
    }
    return 0;
}  
