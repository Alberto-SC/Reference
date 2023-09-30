#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<int> bit;
int N;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}


void add(int idx, int delta) {
    for (++idx; idx < N; idx += idx & -idx) bit[idx] += delta;
}

void add(int l,int r,int delta){
    add(l,delta);
    add(r+1,-delta);
}

signed main(){__
    int t,n,m,l,x,y;
    cin>>n>>m>>l;
    int MX = 1e9;
    vector<int> xs;
    vector<pair<int,int>> F;
    vector<int> queries;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        F.push_back({x,y});
        int z = l-y;
        if(z<0)continue;
        xs.push_back(max(0,x-z));
        xs.push_back(min(x+z,MX));
    }
    for(int i = 0;i<m;i++){
        cin>>x;
        queries.push_back(x);
        xs.push_back(x);
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    bit.resize(xs.size()+1);
    N = xs.size()+1;

    for(int i = 0;i<n;i++){
        x = F[i].first;
        y = F[i].second;
        int z = l-y;
        if(z<0)continue;
        int a = max(0,x-z),b = min(x+z,MX);
        a = lower_bound(xs.begin(),xs.end(),a)-xs.begin();
        b = lower_bound(xs.begin(),xs.end(),b)-xs.begin();
        add(a,b,1);
    }
    
    for(int i = 0;i<m;i++){
        x = queries[i];
        x = lower_bound(xs.begin(),xs.end(),x)-xs.begin();
        cout<<sum(x)<<endl;
    }
    

}   