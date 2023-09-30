#include <bits/stdc++.h>
using namespace std;
struct node{
    int sum,l,r;
    node *left,* right;
    node(int _l,int _r):l(_l),r(_r){sum = (_r-_l)+1,left =right = NULL;}
    void extend(){
        if(l!=r && left== NULL){
            int m = (r+l)/2;
            left = new node(l,m);
            right = new node(m+1,r);
        }
    }
};

void update(node *root,int pos,int val){
    if(pos< root->l || pos> root->r)return ;
    // cout<<root->l<<" "<<root->r<<" "<<root->sum<<endl;
    if(root->l == root->r ){
        root->sum+=val;
        return;
    }
    root->extend();
    update(root->left,pos,val);
    update(root->right,pos,val);
    // cout<<root->left->sum<<" "<<root->right->sum<<endl;
    root->sum = root->left->sum+root->right->sum;
}
int query(node * root,int k){
    // cout<<root->l<<" "<<root->r<<" "<<root->sum<<endl;
    if(root->l == root->r)return root->l;
    root->extend();
    if(root->left->sum>=k)
        query(root->left,k);
    else 
        query(root->right,k-root->left->sum);
}
node *root;
int main() {
    int n, m,q;
    char t;
    cin>>n>>m;
    root = new node(1,n);
    for(int i = 0;i<m;i++){ 
        cin>>t>>q;
        int x = query(root,q);
        if (t == 'L') 
            cout<<x<<endl;
        else 
            update(root,x, -1);
        
    }
    return 0;
}