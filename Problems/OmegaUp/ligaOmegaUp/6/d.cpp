#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct Trie{
    Trie* childs[2];
    lli value;
};

Trie* createNode(){
    Trie* T = new Trie;
    T->childs[0]  = T->childs[1] = NULL;
    return T;
}

void insert(Trie *root,lli val){
    Trie *S = root;
    for(lli i = 60;i>=0;i--){
        bool b = (val>>i)&1;
        if(S->childs[b] == NULL){
            S->childs[b] = createNode();
        }
        S = S->childs[b];
    }
    S-> value = val;
}
lli searchMaxXOR(Trie* root, lli val){
    Trie *S = root;
    lli maximo = 0;
    for(lli i = 60 ;i>=0;i--){
        bool b = (val>>i)&1;
        if(S->childs[1-b]!= NULL)S = S->childs[1-b];
        else if (S->childs[b] != NULL) S =  S->childs[b];
    }
    return val^S->value;
}
int main(){
    lli n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &x:nums)cin>>x;
    Trie* root = createNode();  
    lli mx = -1000;
    insert(root,0);
    lli pre_XOR = 0;
    for(lli i = 0;i<n;i++){
        pre_XOR ^=nums[i];
        insert(root,pre_XOR);
        mx = max(mx,nums[i]);
        mx = max(mx,searchMaxXOR(root,pre_XOR));         
    }
    cout<<mx<<endl;
    return 0;
}