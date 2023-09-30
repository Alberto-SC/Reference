#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<pair<int,int>> st[2] ;
int n;
void update(int idx,int x ,int who,int v = 1,int sl = 0,int sr =n-1){
    if(sl ==sr){
        st[who][v].second+=x;
        if(st[who][v].second==0)st[who][v].first = 1;
        else st[who][v].first = 0;
        return;
    }
    int m = (sl+sr)>>1;
    if(idx<=m)update(idx,x,who,v<<1,sl,m);
    else update(idx,x,who,v<<1|1,m+1,sr);
    st[who][v].first  = st[who][v<<1].first+st[who][v<<1|1].first;
    st[who][v].second  = st[who][v<<1].second+st[who][v<<1|1].second;
    
}

int query(int l,int r,int who,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r || sr <l || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[who][v].first;
    int m = (sl+sr)>>1;
    return query(l,r,who,v<<1,sl,m)+query(l,r,who,v<<1|1,m+1,sr);
}


signed main(){__
    int T = 1,q,x,y,a,b,t;
    while(T--){
        cin>>n>>q;
        st[0].assign(4*n,{0,0});
        st[1].assign(4*n,{0,0});
        for(int i = 0;i<n;i++)
            update(i,0,0),update(i,0,1);
        while(q--){
            cin>>t;
            if(t==1){
                cin>>x>>y;
                x--,y--;
                update(x,1,0);
                update(y,1,1);
            }
            else if(t==2){
                cin>>x>>y;
                x--,y--;
                update(x,-1,0);
                update(y,-1,1);
            }
            else {
                cin>>x>>y>>a>>b;
                x--,y--,a--,b--;
                int x1 = query(x,a,0);
                int x2 = query(y,b,1);
                if(x1 ==0 || x2 ==0)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
    return 0;
}