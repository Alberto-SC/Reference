#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct node{
    int l,r;
    lli value,lazy;
    node* left,*right;
    node(){
        l =1;
        r  = 100000;
        value = 0;
        lazy = 0;
        left = NULL;
        right = NULL;
    }
    void extend(){
        if(left == NULL){
            left = new node();
            right = new node();
            left->l = l;
            left->r = (l+r)/2;
            right->l = ((l+r)/2)+1;
            right->r = r;
        }
    }
};

node *root;
void propagate(node *root){
    if(root->lazy){
        root->value += (root->r-root->l+1)*root->lazy;
        if(root->l!= root->r){
            root->extend();
            root->left->lazy +=root->lazy;
            root->right->lazy += root->lazy;
        }
        root->lazy = 0;
    }
}
void update(node *root,int l,int r,lli v){
    propagate(root);
    if(l> root->r|| r<root->l)return;
    if(root->l>= l && root->r<=r){
        root->lazy +=v;
        propagate(root);
        return;
    }
    root->extend();
    update(root->left,l,r,v);
    update(root->right,l,r,v);
    root->value = root->left->value+root->right->value;
}

lli query(node *root,int l,int r){
    if(r<root->l || l>root->r)return 0;
    propagate(root);
    if(root->l>= l && root->r<=r)return root->value;
    lli a1,a2;
    root->extend();
    a1 = query(root->left,l,r);
    a2 = query(root->right,l,r);
    return a1+a2;
}
int main(){
    lli t,n,l,r,v,m,z;
    cin>>t;
    while(t--){
        cin>>n>>m;
        root = new node();
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