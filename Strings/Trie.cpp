#include <bits/stdc++.h>
using namespace std;
struct Trie{
    unordered_map<char, Trie*> child;
    int prefix;
    bool end;
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
        S->prefix++;
    }
    S-> end =true;
}
 
bool search(struct Trie *root, string key){
    struct Trie *S = root;
    int n = key.size();
    for(int i = 0;i<n;i++){
        if(S->child.find(key[i]) == S->child.end())
            return false;
        S = S->child[key[i]];
    }
    if(S->end)return true;
    else 
        return false;
}

int countprefixes(Trie* root,string s){
    int n= s.size();
    Trie* mov = root;
    for(int i=0;i<n;i++){
        if(mov->child.find(s[i]) == mov->child.end())
             return 0;
        mov=mov->child[s[i]];
    }
    return mov->prefix;
}
Trie* remove(Trie* root, string word, int depth = 0){ 
    if(!root) 
        return NULL; 
    if (depth == word.size()) { 
        if (root->end) 
            root->end = false;  
        if (root->child.size()) { 
            delete (root); 
            root = NULL; 
        } 
        return root; 
    } 
    root->child[word[depth]] =  remove(root->child[word[depth]], word, depth + 1); 
    if (root->child.size()== 0 && root->end == false) { 
        delete(root); 
        root=NULL; 
    } 
    return root; 
} 

void print(Trie* root,char str[],int level){
    if(root->end){
        str[level] = '\0';
        cout<<str<<endl;
    }
    for(auto c:root->child){
        str[level] = c.first;
        print(c.second,str,level+1);
    }
}

int main(){
    int t,n,m;
    string s;
    cin >> t;
    Trie *root = getNode();
    while(t--){
        cin >> s;
        insert(root,s);
    }
    char str[100];
    print(root,str,0);
    cin>>m;
    for(int i = 0;i<m;i++){
        cin>>s;
        remove(root,s);
    }
    print(root,str,0);
}