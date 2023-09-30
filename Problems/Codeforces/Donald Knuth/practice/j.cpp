#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
int P[maxn][25];
vector<int> deep(maxn);
int lca(int u,int v){
    if(deep[u]<deep[v])
        swap(u,v);
    int diff = deep[u]-deep[v];
    for(int i= 24;i>=0;i--)
        if((diff>>i)&1)
            u = P[u][i];
    if(u == v)return u;
    for(int i = 24;i>=0;i--){
        if(P[u][i]!= P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[v][0];
}
signed main(){__
	int t= 1,n,p,u,v;
    cin>>n;
    int last = 0,curr =1;
    for(int i = 0;i<n;i++){
        cin>>t;
        if(t==1){
            cin>>p;
            p=(p+last)%curr;
            p++;
            curr++;
            deep[curr] = deep[p]+1;
            cout<<deep[curr]+1<<endl;       
            P[curr][0]= p;
            last = deep[curr]+1;
            for(int i = 1;i<25;i++)
                if(P[curr][i-1]!=-1)
                    P[curr][i] = P[P[curr][i-1]][i-1];
            
        }
        else{
            cin>>u>>v;
            u=(u+last)%curr;
            u++;
            v=(v+last)%curr;
            v++;
            int LCA = lca(u,v);
            int D = deep[v]+deep[u]-(2*deep[LCA]);
            cout<<D+1<<endl;
            last = D+1;
        }
    }
    return 0;
}  
