#include <bits/stdc++.h>
using namespace std;
struct node{
    int mx,idl,idr;
    node(int l,int r,int w,int _idl = -1,int _idr = -1):mx(w),idl(_idl),idr(_idr){}
};
struct SegmentTree{
    const int l,r;
    vector<node> tree;
    SegmentTree(int low,int h,int w):l(low),r(h){
        tree.reserve((1u << 21) + (1u << 20)); 
        tree.push_back(node(l,r,w));
    }
    void extend(int id,int a,int b){
        if(tree[id].idl == -1){
            int m = (a+b)/2;

            tree.push_back(node(a,m,tree[id].mx));
            tree[id].idl = tree.size()-1;
            tree.push_back(node(m+1,b,tree[id].mx));
            tree[id].idr = tree.size()-1;

        } 
    }

    void update(int id ,int pos,int val,int a  ,int b ){
        if(pos<a || pos >b)return ;
        if(a == b){
            tree[id].mx -= val;
            return;
        }
        extend(id,a,b);
        int m = (a+b)/2;
        const int idl = tree[id].idl; assert(idl != -1);
        const int idr = tree[id].idr; assert(idr != -1);
        update(idl,pos,val,a,m);
        update(idr,pos,val,m+1,b);
        tree[id].mx = max(tree[idl].mx,tree[idr].mx);
    }
    int query(int id,int k,int a ,int b ){
        if(a == b)return a;
        extend(id,a,b);
        const int idl = tree[id].idl;  assert(idl != -1);
        const int idr = tree[id].idr; assert(idr != -1);   
        int m = (a+b)>>1;
        if(tree[idl].mx>= k)
            return query(idl,k,a,m);
        else 
            return query(idr,k,m+1,b);    
    }

};
int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    int h,w,n,q;
    cin>>h>>w>>n;
    SegmentTree st(1,h+1,w);
    for(int i = 0;i<n;i++){
        cin>>q;
        int pos = st.query(1,q,1,h+1);
        if(pos == h+1)cout<<-1<<endl;
        else cout<<pos<<endl;
        st.update(1,pos,q,1,h+1);
    }
    return 0;
}