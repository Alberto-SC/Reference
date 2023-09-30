#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> p;
vector<int> sz;

int root(int u){
    return p[u]==u?u:p[u] = root(p[u]);
}

bool union_by_size(int u,int v){
    u = root(u);
    v = root(v);
    if(u==v)return false;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    return true;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        sz.assign(n,1);
        p.resize(n);
        iota(p.begin(),p.end(),0);
        int ans = 0;
        for(int bit = 0;bit<32;bit++){
            vector<pair<int,int>> nbit(n);
            for(int i = 0;i<n;i++){
                nbit[i] = {(nums[i]>>bit)&1,i};
            }
            sort(nbit.begin(),nbit.end());
            for(int i =0;i<n-1;i++){
                if(nbit[i].first ==1 && nbit[i+1].first ==1){
                    int u = nbit[i].second;
                    int v = nbit[i+1].second;
                    if(union_by_size(u,v)){
                        ans+=(1<<bit);
                    }
                }
            }
        }
        set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(root(i));
        }
        if(st.size()>1)cout<<-1<<endl;
        else 
            cout<<ans<<endl;
    }
    return 0;
}