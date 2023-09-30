#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli n,m,x,y;
    cin>>n>>m;
    vector<lli> diag[n+n+n];
    vector<lli> diag2[n+n+1];
    vector<lli> cols[n];
    vector<lli> rows[n];
    vector<lli> ans(9);
    vector<pair<lli,lli>> q;
    auto f = [&](lli x,lli y){
        return (x*n)+y;
    };
    for(lli i = 0;i<m;i++){
        cin>>x>>y;
        y--,x--;
        q.push_back({x,y});
    }
    sort(q.begin(),q.end());
    for(lli i = 0;i<m;i++){
        x = q[i].first;
        y = q[i].second;        
        cols[y].push_back(f(x,y));
        rows[x].push_back(f(x,y));
        diag[(x-y)+n].push_back(f(x,y));
        diag2[x+y].push_back(f(x,y));
    }
    for(lli i = 0;i<m;i++){
        x = q[i].first;
        y = q[i].second;
        lli w= 0;
        auto idx = lower_bound(cols[y].begin(),cols[y].end(),f(x,y))-cols[y].begin();
        if(cols[y].size()>1){
            w++;
            if(idx>0 && idx<cols[y].size()-1)w++;

        }
        idx = lower_bound(rows[x].begin(),rows[x].end(),f(x,y))-rows[x].begin();
        if(rows[x].size()>1){
            w++;
            if(idx>0 && idx<rows[x].size()-1)w++;
        }
        idx = lower_bound(diag[(x-y)+n].begin(),diag[(x-y)+n].end(),f(x,y))-diag[(x-y)+n].begin();
        if(diag[(x-y)+n].size()>1){
            w++;
            if(idx>0 && idx<diag[(x-y)+n].size()-1)w++;
        }

        idx = lower_bound(diag2[x+y].begin(),diag2[x+y].end(),f(x,y))-diag2[x+y].begin();
        if(diag2[x+y].size()>1){
            w++;
            if(idx>0 && idx<diag2[x+y].size()-1)w++;
        }
        // cout<<idx<<endl;
        ans[w]++;
    }   
    for(lli i = 0;i<=8;i++)
        cout<<ans[i]<<" ";    

    cout<<endl;
    return 0;
}