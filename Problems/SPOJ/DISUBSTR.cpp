#include <bits/stdc++.h>
#define pb push_back
using namespace std;
string s;
int t;
int ans = 0;
struct Trie{
    unordered_map<char, Trie*> child;
};
 
struct Trie *getNode(){
    struct Trie *p = new Trie;
    return p;
}
 
void insert(struct Trie *root, string key){
    struct Trie *S = root;
    for(int i = 0 ; i < key.length(); i++){
        if(S->child.find(key[i]) == S->child.end())
            S->child[key[i]] = getNode();
 
        S = S->child[key[i]];
    }
}
 
void calculate(struct Trie *root){
    for(auto it = root->child.begin() ; it != root->child.end() ; it++){
        ans++;
        calculate(it->second);
    }
}
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> s;
        Trie *root = getNode();
        for(int i = 0 ; i < s.length() ; i++)
            insert(root, s.substr(i));
        ans = 0;
        calculate(root);
        cout << ans << endl;
    }
}