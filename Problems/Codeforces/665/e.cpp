
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 1000000;
vector<int> bit(maxn+3);
vector<int> s[maxn+3];
vector<int> e[maxn+3];
vector<pair<int,int>> v[maxn+3];

void add(int idx,int val){
    for(++idx;idx<maxn+3;idx += idx&-idx)bit[idx]+=val;
}
int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx -= idx& -idx)res+=bit[idx];
    return res;
}

int query(int a,int b){
    return sum(b)-sum(a-1);
}

int main(){__
    int n,m,x,y,l,r;
    cin>>n>>m;
    lli ans = 1;
    for(int i= 0;i<n;i++){
        cin>>y>>l>>r;
        if(l == 0 && r == maxn)ans++;
        s[l].push_back(y);
        e[r].push_back(y);
    }
    for(int i = 0;i<m;i++){
        cin>>x>>l>>r;
        if(l == 0 && r == maxn)ans++;
        v[x].push_back({l,r});
    }
    for(int i = 0;i<=maxn;i++){
        for(auto y:s[i])
            add(y,1);
        for(auto x:v[i])
            ans+= query(x.first,x.second);
        for(auto y:e[i])
            add(y,-1);
    }
    cout<<ans<<endl;
    return 0;
}