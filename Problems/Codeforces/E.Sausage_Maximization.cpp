#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct Trie{
    Trie* childs[2];
    lli value;
};
Trie* createNode(){
    Trie* S = new Trie();
    S->childs[0] = S->childs[1] = NULL;
    return S;
}

void insert(Trie *root,lli val){
    Trie *S = root;
    for(int i = 50;i>=0;i--){
        bool b = (val>>i)&1;
        if(S->childs[b] == NULL){
            S->childs[b] = createNode();
        }
        S = S->childs[b];
    }
    S-> value = val;
}
lli search(Trie* root, lli val){
    Trie *S = root;
    int maximo = 0;
    for(int i = 50 ;i>=0;i--){
        bool b = (val>>i)&1;
        if(S->childs[1-b]!= NULL)S = S->childs[1-b];
        else if (S->childs[b] != NULL) S =  S->childs[b];
    }
    return val^S->value;
}
int main(){
    int n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &x:nums)cin>>x;
    Trie *root = createNode();
    lli pre_xor = 0;
    for(int i = 0;i<n;i++){
        pre_xor^= nums[i];
    }
    lli suff_xor = 0;
    lli ans = -10000;
    for(int i = n-1;i>=0;i--){
        // cout<<pre_xor<<"  "<<suff_xor<<endl;
        insert(root,suff_xor);
        ans = max(ans,search(root,pre_xor));
        suff_xor^=nums[i];
        pre_xor^=nums[i];
    }
    insert(root,suff_xor);
    ans = max(ans,search(root,pre_xor));
    cout<<ans<<endl;
    return 0;
}