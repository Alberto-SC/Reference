#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

struct Trie{
    unordered_map<char, Trie*> child;
    int prefix;
    bool end;
    long long pi;
};

struct Trie *getNode(){
    struct Trie *p = new Trie;
    p->end = false;
    p->pi = 0;
    p->prefix = 0;
    return p;
}
 
void insert(struct Trie *root, string key, long long pi){
    struct Trie *S = root;
    for(int i = 0 ; i < key.length(); i++){
        if(S->child.find(key[i]) == S->child.end())
            S->child[key[i]] = getNode();
 
        S = S->child[key[i]];
        S->prefix++;
    }
    S-> end =true;
    S->pi = pi;
}

long long res = 0;

void print(Trie* root,long long acum){
    if(root->end){
        if(acum + root->pi > res){
            res = acum + root->pi;
        }
    }
    for(auto c:root->child){
        print(c.second,acum+root->pi);
    }
}

signed main(){
    int t,n,m;
    string s;
    cin >> t;
    Trie *root = getNode();
    while(t--){
        cin >> s;
        long long pi; cin>>pi;
        insert(root,s, pi);
    }
    char str[100];
    print(root,0);

    cout << res << "\n";
    return 0;
}

