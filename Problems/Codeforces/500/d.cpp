#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int f[440000];
int find_set(int i){
    return f[i] == i ? i: f[i] = find_set(f[i]);
    }

int main(){
    ios_base::sync_with_stdio(0);
    int n,m,q,r,c;
    cin>>n>>m>>q;
    for(int i = 1;i<=n+m;i++)f[i] = i;
    int ans = n+m;
    for(int i = 0;i<q;i++){
        cin>>r>>c;
        int u = find_set(f[r]);
        int v = find_set(f[c+n]);
        if(u==v)continue;
        f[u] = v;
        ans--;
    }
    cout<<ans-1<<endl;
    return 0;
}
 