#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> graph2[maxn];
vector<int> c(maxn);
vector<int> c2(maxn);
vector<int> leafs;
vector<lli> sums(maxn);
lli mx = -1;
void dfs(int u,lli sum = 0){
    sum+=c[u];
    int cont = 0;
    for(auto v:graph[u]){
        dfs(v,sum);
        cont++;
    }
    if(cont==0)leafs.push_back(u);
    sums[u] = sum;
    mx = max(sums[u],mx);
}
int n;

void dfs2(int u,int sum){
    c2[u] = min(sum,c[u]);
    sum-=c2[u];
    for(auto v: graph[u]){
        dfs(v,sum);
    }
}

bool check(int u){
    c2.assign(n,0);
    for(auto c:leafs)
        dfs2(c,sums[c]);
    if(c2[0]>=c[0])return true;
    return false;
}

int main(){__
    int t = 1,p;
    cin>>n;
    for(int i = 1;i<n;i++){
        cin>>p;
        graph[p-1].push_back(i);
        graph2[i].push_back(p-1);
    }
    for(int i = 0;i<n;i++)        
        cin>>c[i];
    dfs(0);
    sort(leafs.begin(),leafs.end(),[&](int u,int v){
        return sums[u]<sums[v];
    });
    int l = 0,r = mx;
    while(l+1<r){
        int mid = (l+r)>>1;
        cout<<mid<<" "<<check(mid)<<endl;  
        if(check(mid))
            l = mid;
        else 
            r = mid;
    }
    cout<<l<<endl;
    return 0;
}

