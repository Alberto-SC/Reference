#include <bits/stdc++.h>
using namespace std;

struct node{
    int sum,idl,idr;
    node(int l,int r,int idl = -1,int idr = -1): sum((r-l)+1),idl(idl),idr(idr){}
};

int n;
vector<node> tree;

void extend(int id,int l,int r){
    if(tree[id].idl!=-1)return ;
    int m = (l+r)>>1;
    tree[id].idl = tree.size();
    tree.push_back(node(l,m));
    tree[id].idr = tree.size();
    tree.push_back(node(m+1,r));
}

void update(int idx,int v,int id = 0,int l = 0,int r = n-1){
    extend(id,l,r);
    if(l == r)tree[id].sum+=v;
    else{
        int m = (l+r)>>1;
        int idl = tree[id].idl;
        int idr = tree[id].idr;
        if(idx<=m)
            update(idx,v,idl,l,m);
        else 
            update(idx,v,idr,m+1,r);
        tree[id].sum = tree[idl].sum+tree[idr].sum;
    }
}

int query(int k,int id = 0,int l = 0,int r = n-1){
    if(l ==r)return l;
    int m = (l+r)>>1;
    extend(id,l,r);
    int idl = tree[id].idl;
    int idr = tree[id].idr;
    if(tree[idl].sum>=k)
        return query(k,idl,l,m);
    else 
        return query(k-tree[idl].sum,idr,m+1,r);
}

int main(){
    int m,x;
    char t; 
    cin>>n>>m;
    tree.reserve(1u<<22);
    tree.push_back(node(0,n-1));
    for(int i = 0;i<m;i++){
        cin>>t>>x;
        int real = query(x);
        if(t == 'D')
            update(real,-1);
        else
            cout<<real+1<<endl;
    }

    return 0;
}