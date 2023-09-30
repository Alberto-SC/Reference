#include <bits/stdc++.h>
using namespace std;
struct Trie{
    Trie* children[10];
    int alph[10];
    bool end;
};

Trie* createNode(){
    Trie* parent = new Trie;
    parent->end = false;
    for(int i = 0;i<10;i++){
        parent->children[i] = NULL;
    }
    return parent;
}

void insert(string key,Trie* root){
    Trie* S = root;
    int n = key.size();
    for(int i = 0;i<n;i++){
        int index = key[i]-'0';
        if(!S->children[index]){
            S->children[index] = createNode();
        }
        S = S->children[index];
    }
    S->end = true;
}
bool search(string key, Trie* root){
    Trie* S = root;
    int n = key.size();
    for(int i = 0;i<n;i++){
        int index = key[index]-'0';
        S = S->children[index];
        if(S->end == true)return true;
    }
    return false;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<string> dict(n);
        bool flag = true;
        Trie* root = createNode();
        for(int i = 0;i<n;i++){    
            cin>>dict[i];
        }
        for(int i = 0;i<n;i++){
            insert(dict[i],root);
        }
        for(int i = 0;i<n;i++){
            if(search(dict[i],root)){flag =false;break;}
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}