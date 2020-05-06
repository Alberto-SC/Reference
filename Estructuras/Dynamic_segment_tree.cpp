#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node{
    int l,r;
    lli sum,lazy;
    node* left,*right;
    node(int _l,int _r):l(_l),r(_r){sum = lazy = 0;left = right =  NULL;}
    void extend(){
        if(left == NULL){
            left = new node(l,(l+r)/2);
            right = new node(((l+r)/2)+1,r);
        }
    }
    void propagate(){
        if(!lazy)return;
        sum+= ((r-l)+1)*lazy;
        if(l!= r){
            extend();
            left->lazy+=lazy;
            right->lazy+=lazy;
        }
        lazy = 0;
    }
};
void update(node *root,int l,int r,lli v){
    root->propagate();
    if(l> root->r|| r<root->l)return;
    if(root->l>= l && root->r<=r){
        root->lazy +=v;
        root->propagate();
        return;
    }
    root->extend();
    update(root->left,l,r,v);
    update(root->right,l,r,v);
    root->sum = root->left->sum+root->right->sum;
}


lli query(node *root,int l,int r){
    if(r<root->l || l>root->r)return 0;
    root->propagate();
    if(root->l>= l && root->r<=r)return root->sum;
    lli a1,a2;
    root->extend();
    a1 = query(root->left,l,r);
    a2 = query(root->right,l,r);
    return a1+a2;
}
node *root;
int main(){
    lli t,n,l,r,v,m,z;
    cin>>t;
    while(t--){
        cin>>n>>m;
        root = new node(1,n);
        for(int i = 0;i<m;i++){
            cin>>z;
            if(z == 0){
                cin>>l>>r>>v;
                update(root,l,r,v);
            }
            else {
                cin>>l>>r;
                cout<<query(root,l,r)<<endl;
            }
        }
    }
    return 0;
}