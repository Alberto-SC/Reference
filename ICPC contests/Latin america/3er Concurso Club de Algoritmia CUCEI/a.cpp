#include <bits/stdc++.h>
using namespace std;
const int ALPH = 40;
struct trieNode{
    map<char, trieNode*> child;
    bool end;
    int prefix;
};
 
struct trieNode *getNode(){
    struct trieNode *p = new trieNode;
    p->prefix = 0;
    p->end = false;
    return p;
}
 
void insert(struct trieNode *root, string key){
    struct trieNode *S = root;
    for(int i = 0 ; i < key.length(); i++){
        if(S->child.find(key[i]) == S->child.end())
            S->child[key[i]] = getNode();
 
        S = S->child[key[i]];
    }
    S-> end =true;
}
    
void insert2(struct trieNode *root, string key){
    struct trieNode *S = root;
    for(int i = 0 ; i < key.length(); i++){
        if(S->child.find(key[i]) != S->child.end()){
            S = S->child[key[i]];
        }
        else return;
    }
    S-> prefix++;
}



vector<string> ans;
void print(trieNode* root, char str[], int level) { 
    if (root->end){ 
        str[level] = '\0';
        ans.push_back(str); 
    } 
    for (auto c:root->child){ 
        if (c.second->prefix == 0){
            str[level] = c.first; 
            print(c.second, str, level + 1); 
        } 
    } 
} 
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    trieNode* root = getNode();
    for(int i = 0;i<n;i++){
        cin>>s;
        insert(root,s);
    }  
    for(int i = 0;i<m;i++){
        cin>>s;
        insert2(root,s);
    }
    char str[1000];
    print(root,str,0);
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c<<endl;
}