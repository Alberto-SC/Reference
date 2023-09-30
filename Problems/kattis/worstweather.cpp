#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int inf = 1e9+7;
struct Node{
    int l,r,mx,mn,idl,idr;
    Node(int _l,int _r,int _mn,int _mx):l(_l) ,r(_r) ,mx(_mx),mn(_mn),idl(-1),idr(-1){}
};


struct SegTree{
    vector<Node> st;
    SegTree(int l = -inf,int r = inf ){
        st.push_back({l,r,-inf,-inf});
    }

    void extend(int v){
        int l = st[v].l,r = st[v].r;
        int m = (l+r)>>1;
        if(st[v].idl==-1 && l!=r){
            st[v].idl = st.size();
            st.push_back({l,m,st[v].mn,st[v].mx});
            st[v].idr = st.size();
            st.push_back({m+1,r,st[v].mn,st[v].mx});
        }
    }

    void update(int idx,int val,int v = 0){
        extend(v);
        int l = st[v].l,r = st[v].r;
        int m = (l+r)>>1;
        int idl = st[v].idl,idr = st[v].idr;
        if(l == r){
            st[v].mn = val;
            st[v].mx = val;
            return;
        }
        if(idx<=m) 
            update(idx,val,idl);
        else
            update(idx,val,idr);
        st[v].mn = min(st[idl].mn,st[idr].mn);
        st[v].mx = max(st[idl].mx,st[idr].mx);
    }

    int queryMin(int l,int r,int v = 0){
        extend(v);
        if(l>r)return inf;
        int sl = st[v].l,sr = st[v].r;
        int idl = st[v].idl,idr = st[v].idr;
        if(sl>r || sr<l)return inf;
        else if(sl>=l && sr<=r)return st[v].mn;
        int m = (l+r)>>1;
        return min(queryMin(l,r,idl),queryMin(l,r,idr));
    }
    int queryMax(int l,int r,int v = 0){
        extend(v);
        if(l>r)return -inf;
        int sl = st[v].l,sr = st[v].r;
        int idl = st[v].idl,idr = st[v].idr;
        if(sl>r || sr<l)return -inf;
        else if(sl>=l && sr<=r)return st[v].mx;
        int m = (l+r)>>1;
        return max(queryMax(l,r,idl),queryMax(l,r,idr));
    }
};

signed main(){
    int t,n,y,x,r,q;
    while(cin>>n){
        SegTree ST;

        for(int i = 0;i<n;i++){
            cin>>y>>r;
            ST.update(y,r);
        }
        cin>>q;
        if(n == 0 && q == 0)break;
        for(int i = 0;i<q;i++){
            cin>>x>>y;
            int r1 = ST.queryMax(x,x);
            int r2 = ST.queryMax(y,y);
            int middle = ST.queryMax(x+1,y-1);
            int middleM = ST.queryMin(x+1,y-1);
            // cout<<r1<<" "<<r2<<" "<<middle<<" "<<middleM<<endl;
            if(r1 == r2  && r1 == -inf)cout<<"maybe"<<endl;
            else if(r2  == -inf){
                if(middle<r1)
                    cout<<"maybe"<<endl;
                else cout<<"false"<<endl;
            }
            else if(r1 == -inf){
                if(middle<r2)
                    cout<<"maybe"<<endl;
                else cout<<"false"<<endl;
            }
            else if(r1>=r2 && middle<r2){
                if(middleM == -inf)cout<<"maybe"<<endl;
                else cout<<"true"<<endl;
            }
            else cout<<"false"<<endl;
        }
        cout<<endl;
    }
}   