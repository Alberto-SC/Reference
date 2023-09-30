#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> p(5007);
vector<int> sz(5007);
int get_root(int i ){
    return i== p[i]?i:p[i] = get_root(p[i]);
}

bool unite(int u,int v){
    u = get_root(u);
    v = get_root(v);
    if(u==v)return false;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v]= u;
    return true;
}

int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> ai(n);
        sz.assign(n,1);
        iota(p.begin(),p.end(),0);
        for(auto &c:ai)cin>>c;
        vector<pair<int,int>> ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(ai[i]!= ai[j] && unite(i,j)){
                    ans.push_back({i+1,j+1});
                }
            }
        }
        if(ans.size()<n-1)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
        }
    }
    return 0;
}

