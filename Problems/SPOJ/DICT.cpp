#include <bits/stdc++.h>
using namespace std;


struct Trie{
    Trie* childs[27];
    bool end;
    string word;
};
Trie* createNode(){
    Trie* r = new Trie;
    for(int i = 0;i<27;i++){
        r->childs[i] = NULL;
    }
    r->end = false;
    return r;
}

void insert(Trie *root,string key){
    Trie *S = root;
    int n = key.size(),index;
    for(int i = 0;i<n;i++){
        index = key[i]-'a';
        if(S->childs[index]  == NULL)
            S->childs[index] = createNode();
        S = S->childs[index];
    }
    S-> end = true;
    S-> word = key;
}
int getAll(Trie * root,string s,int &cont){
    if(root->end && root->word!= s){cont++;cout<<root->word<<endl;}
    for(int i = 0;i<27;i++){
        if(root->childs[i]!= NULL)
            getAll(root->childs[i],s,cont);
    }
    return cont;
}
int searchpreffix(Trie *root,string key){
    Trie *S = root;
    int n = key.size(),index;
    for(int i = 0;i<n;i++){
        index = key[i] -'a';
        if(S->childs[index] == NULL)return 0;
        S = S->childs[index];
    }
    int cont= 0;
    getAll(S,key,cont);
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n,k;
    cin>>n;
    vector<string> dict(n);
    for(auto &x:dict)cin>>x;
    Trie *root = createNode();
    for(int i = 0;i<n;i++){
        insert(root,dict[i]);
    }
    cin>>k;
    vector<string>ss(k);
    for(auto &x: ss)cin>>x;
    for(int i = 0;i<k;i++){
        cout<<"Case #"<<i+1<<":"<<endl;
        if(searchpreffix(root,ss[i])  == 0)cout<<"No match."<<endl;
    }
    return 0;
}