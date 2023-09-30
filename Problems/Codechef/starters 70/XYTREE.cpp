#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 300007;
vector<int> nums(maxn);
vector<int> start(maxn),End(maxn);
vector<int> graph[maxn];
vector<int> leaf(maxn);
int id = 0;
void dfs(int u,int p = -1){
    start[u] = id++;
    int childs = 0;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u);
        childs++;
    }
    if(childs==0)leaf[u] = 1;
    End[u] = id-1;
}

vector<int> bit(maxn);

void add(int idx,int val){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=val;
}

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}
int sum(int l,int r){
    return sum(r)-sum(l-1);
}

void print(int n){
    for(int i = 0;i<n;i++){
        cout<<sum(i,i)<<" ";
    }
    cout<<endl;
}

signed main(){__
    int T = 1,n,u,v,q;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0;i<n;i++){
            leaf[i] = 0;
            graph[i].clear();
        }

        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        id = 0;
        dfs(0);
        cin>>q;
        int bad = 0;
        bool complete = false;
        vector<int> toClean;
        set<int> bads;
        while(q--){
            int t;
            cin>>t;
            if(t ==1){
                cin>>u;
                u--;
                if(bads.count(u))continue;
                if(leaf[u]){
                    bad++;
                    add(start[u],1);
                    toClean.push_back(start[u]);
                    bads.insert(u);
                }
                else{
                    int s = sum(start[u]+1,End[u]);
                    int l = (End[u]-start[u])+1;
                    if(s ==l-1){
                        if(l ==n)complete = true;
                        add(start[u],1);
                        toClean.push_back(start[u]);
                        bads.insert(u);
                    }
                }
            }
            else{
                if(complete)cout<<n-1<<endl;
                else cout<<(n-1)-bads.size()<<endl;;
            }
        }
        for(auto c:toClean){
            add(c,-1);
        }

    }
    return 0;
}