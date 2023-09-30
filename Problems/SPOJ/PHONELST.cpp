#include <bits/stdc++.h>
using namespace std;
struct Trie{
    Trie* children[10];
    int preffix;
    bool end;
};

Trie* CreateNode(){
    Trie* Parent = new Trie;
    Parent->preffix = 0;
    Parent->end = false;
    for(int i = 0;i<10;i++)
        Parent->children[i] = NULL;
    return Parent;
}

void insert(Trie* root, string key ){
    Trie* S = root;
    for(int i = 0;i<key.size();i++){
        int index = key[i]-'0';
        if(!S->children[index]){
            S->children[index] = CreateNode();
        }
        S = S->children[index];
        S->preffix++;
    }
    S->end = true;
}
int countpreffix(Trie* root,string word){
    Trie * S = root;
    for(int i = 0;i<word.size();i++){
        int index = word[i]-'0';
        if(!S->children[index])return 0;
        S = S->children[index];
    }
    return S->preffix;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        string dictionary[n];
        Trie* root = CreateNode();
        bool yes = true;
        for(int i = 0;i<n;i++){
            cin>>dictionary[i];
            insert(root,dictionary[i]);
        }
        for(int i = 0;i<n;i++)
            if(countpreffix(root,dictionary[i])>1)yes = false;
        yes? cout<<"YES"<<endl: cout<<"NO"<<endl;
    }

}
