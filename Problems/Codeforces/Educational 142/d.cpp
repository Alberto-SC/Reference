#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct Trie{
    unordered_map<int, Trie*> child;
    int prefix;
    bool end;
};
 
struct Trie *getNode(){
    struct Trie *p = new Trie;
    p->end = false;
    p->prefix = 0;
    return p;
}
 
void insert(struct Trie *root, vector<int> key){
    struct Trie *S = root;
    for(int i = 0 ; i < key.size(); i++){
        if(S->child.find(key[i]) == S->child.end())
            S->child[key[i]] = getNode();
 
        S = S->child[key[i]];
        S->prefix++;
    }
    S-> end =true;
}
 
int search(struct Trie *root, vector<int> key){
    struct Trie *S = root;
    int n = key.size();
    int cont = 0;
    for(int i = 0;i<n;i++){
        if(S->child.find(key[i]) == S->child.end())
            return cont;
        S = S->child[key[i]];
        cont++;
    }
    return cont;
}

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums[n];
        Trie *root = getNode();
        for(int i = 0;i<n;i++){
            nums[i].resize(m);
            for(auto &c:nums[i])cin>>c;

            vector<int> nw(m);
            for(int j = 0;j<m;j++){
                nw[nums[i][j]-1] = j+1;
            }
            insert(root,nw);
        }

        for(int i = 0;i<n;i++){
            int ans = search(root,nums[i]);
            cout<<ans<<" ";
        }
        cout<<endl;


    }
    return 0;
}