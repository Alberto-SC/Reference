#include <bits/stdc++.h>
using namespace std;
struct Trie{
    Trie* childs[2];
    int value;
};

Trie* createNode(){
    Trie* T = new Trie;
    T->childs[0]  = T->childs[1] = NULL;
    return T;
}

void insert(Trie *root,int val){
    Trie *S = root;
    for(int i = 31;i>=0;i--){
        bool b = (val>>i)&1;
        if(S->childs[b] == NULL){
            S->childs[b] = createNode();
        }
        S = S->childs[b];
    }
    S-> value = val;
}
int searchMaxXOR(Trie* root, int val){
    Trie *S = root;
    int maximo = 0;
    for(int i = 31 ;i>=0;i--){
        bool b = (val>>i)&1;
        if(S->childs[1-b]!= NULL)S = S->childs[1-b];
        else if (S->childs[b] != NULL) S =  S->childs[b];
    }
    return val^S->value;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums)cin>>x;
        Trie* root = createNode();  
        int mx = -1000;
        insert(root,0);
        int pre_XOR = 0;
        for(int i = 0;i<n;i++){
            pre_XOR ^=nums[i];
            insert(root,pre_XOR);
            mx = max(mx,nums[i]);
            mx = max(mx,searchMaxXOR(root,pre_XOR));         
        }
        cout<<mx<<endl;
    }
    return 0;
}