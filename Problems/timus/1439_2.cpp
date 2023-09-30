#include <bits/stdc++.h>
using namespace std;
struct node{
    int sum,idl,idr;
    node(int l,int r,int _idl = -1,int _idr = -1):sum((r-l)+1),idl(_idl),idr(_idr){}
};

struct SegmentTree{
    const int l,r;
    vector<node> tree;
    SegmentTree(int low,int h):l(low),r(h){
        tree.reserve((1u << 21) + (1u << 20)); 
        tree.push_back(node(l,r));
    }
    void extend(int id,int a,int b){
        if(tree[id].idl == -1){
            int m = (a+b)/2;
            tree.push_back(node(a,m));
            tree[id].idl = tree.size()-1;
            tree.push_back(node(m+1,b));
            tree[id].idr = tree.size()-1;

        } 
    }

    void update(int id ,int pos,int val,int a  ,int b ){
        if(pos<a || pos >b)return ;
        if(a == b){
            tree[id].sum += val;
            return;
        }
        extend(id,a,b);
        int m = (a+b)/2;
        const int idl = tree[id].idl; assert(idl != -1);
        const int idr = tree[id].idr; assert(idr != -1);
        update(idl,pos,val,a,m);
        update(idr,pos,val,m+1,b);
        // cout<<a<<" "<<b<<" "<<tree[idl].sum<<" "<<tree[idr].sum<<endl;
        tree[id].sum = tree[idl].sum+tree[idr].sum;
    }
    int query(int id,int k,int a ,int b ){
        if(a == b)return a;
        extend(id,a,b);
        const int idl = tree[id].idl;  assert(idl != -1);
        const int idr = tree[id].idr; assert(idr != -1);   
        int m = (a+b)>>1;
        if(tree[idl].sum>= k)
            return query(idl,k,a,m);
        else 
            return query(idr,k-tree[idl].sum,m+1,b);    
    }

};
int main() {
    int n, m,q;
    char t;
    cin>>n>>m;
    SegmentTree st(1,n);
    for(int i = 0;i<m;i++){ 
        cin>>t>>q;
        int x = st.query(0,q,1,n);
        if (t == 'L') 
            cout<<x<<endl;
        else 
            st.update(0,x, -1,1,n);
        
    }
    return 0;
}