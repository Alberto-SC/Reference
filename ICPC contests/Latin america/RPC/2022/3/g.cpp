#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<int> bit;
int N;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < N; idx += idx & -idx) bit[idx] += delta;
}

struct event{
    int x,l,r,op;
};
struct rect{
    int x,y,a,b;
};

signed main(){__
    int t,n,x1,x2,y1,y2;
    cin>>n;
    vector<int>_all;
    vector<rect> R;
    for(int i = 0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        _all.push_back(y1);
        _all.push_back(y2);
        R.push_back({x1,y1,x2,y2});
    }
    sort(_all.begin(),_all.end());
    _all.erase( unique( _all.begin(), _all.end() ), _all.end() );
    vector<event> E;
    for(int i = 0;i<n;i++){
        int l = lower_bound(_all.begin(),_all.end(),R[i].y)-_all.begin();
        int r = lower_bound(_all.begin(),_all.end(),R[i].b)-_all.begin();
        E.push_back({R[i].x,l,r,+1});
        E.push_back({R[i].a,l,r,-1});
    }

    sort(E.begin(),E.end(),[&](event a,event b){
        if(a.x==b.x){
            if(a.op== b.op){
                if(a.op==1){
                    if(a.l==b.l)return a.r<b.r;
                    return a.l>b.l;
                }
                else{
                    if(a.l==b.l)return a.r>b.r;
                    return a.l<b.l;
                }

            }
            return a.op>b.op;
        }
        return a.x<b.x;
    });
    N = _all.size()+1;
    bit.resize(N);
    bool flag = false;
    for(auto e:E){
        if(e.op==1 &&sum(e.l,e.r))flag = true;
        if(e.op==-1 &&sum(e.l,e.r)>2)flag = true;
        add(e.l,e.op);
        add(e.r,e.op);
    }
    if(flag)cout<<1<<endl;
    else cout<<0<<endl;

}   