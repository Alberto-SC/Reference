#include <bits/stdc++.h>
using namespace std;
bool bads[26];
int allow;
struct Trie{
    Trie* childs[26];
    bool end;
    int bad;
};
Trie* createNode(){
    Trie* S = new Trie;
    for(int i = 0;i<26;i++){
        S->childs[i] = NULL;
    }
    S->end = false;
    S->bad = 0;
    return  S;
}
void insert(Trie *root,string key){
    Trie *S = root;
    int n = key.size(),badwords = 0,index;
    for(int i = 0;i<n;i++){
        index = key[i]-'a';
        if(S->childs[index]!= NULL){
            S = S->childs[index];
            badwords = S->bad;
        }
        else {
            S->childs[index]= createNode();
            S = S->childs[index];
            if(!bads[index])badwords++;
            S->bad = badwords;
        }   
    }
    S->end = true;
}
int ans = 0;
int dfs(Trie *root){
    if(root->bad >allow)return 0;
    for(int i = 0;i<26;i++){
        if(root->childs[i]!= NULL){
            ans+=dfs(root->childs[i]);
        }
    }
    return 1;
}
int main(){
    string s,b;
    cin>>s;
    cin>>b;
    for(int i = 0;i<26;i++)
        b[i]=='0'?bads[i]= false:bads[i] = true;    
    cin>>allow;
    Trie *root = createNode();
    for(int i = s.size()-1;i>=0;i--)
        insert(root,s.substr(i));

    dfs(root);
    cout<<ans<<endl;
    return 0;
}