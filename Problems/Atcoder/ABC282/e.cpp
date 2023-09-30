#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct s{
    int u,v,sc;
};

int mod;
int mod_pow(int a,int b){
    int x= 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T = 1,n,m;
    cin>>n>>m;
    mod = m;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<s> V;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            V.push_back({i,j,(mod_pow(nums[i],nums[j])+mod_pow(nums[j],nums[i]))%mod});
        }
    }
    sort(V.begin(),V.end(),[&](s a,s b){
        return a.sc> b.sc;
    });
    int ans = 0;
    int N = V.size();
    vector<int> used(n+1);
    vector<int> nxt[n];
    for(int i = N-1;i>=0;i--){
        nxt[V[i].u].push_back(i);
        nxt[V[i].v].push_back(i);
    }
    for(int i = 0;i<N;i++){
        // cout<<i<<" : "<<V[i].sc<<" "<<V[i].u<<" "<<V[i].v<<endl;
        int u = V[i].u;
        int v = V[i].v;
        nxt[u].pop_back();
        nxt[v].pop_back();
        if(used[u] || used[v])continue;
        ans+=V[i].sc;
        if(nxt[u].size()==0)used[u] = true;
        else if(nxt[v].size()==0)used[v] = true;
        else {
            int n1 = N+1,n2 = N+1;
            int id = nxt[u].size()-1;
            while(id>=0){
                int j = nxt[u][id];
                int nu = V[j].u,nv = V[j].v;
                if(!used[nu] && !used[nv]){
                    n1 = j;
                    break;
                }
                id--;
            }
            id = nxt[v].size()-1;
            while(id>=0){
                int j = nxt[v][id];
                int nu = V[j].u,nv = V[j].v;
                if(!used[nu] && !used[nv]){
                    n2 = j;
                    break;
                }
                id--;
            }
            // cout<<n1<<" "<<n2<<endl;
            if(n1<n2)used[v] = true;
            else used[u] = true;

        }    
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}