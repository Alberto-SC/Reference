#include <bits/stdc++.h>
using namespace std;
const int ALPH =26;
struct trieNode{
    trieNode* child[26];
    int  end;
    int ramas;
};
trieNode* createNode(){
    trieNode* t= new trieNode;
    if(t){
        t->end =0;
        t->ramas =0;
        for(int i =0;i<ALPH;i++){
            t->child[i]=NULL;
        }
    }
    return t;
}
void insert(trieNode* root,string key){
        trieNode* move = root;
        for(int i = 0;i<key.size();i++){
            int index = key[i]-'a';
            if(!move->child[index]){

                move->child[index]=createNode();
                move->ramas++;
            }
            move = move->child[index];
        }
        move->end =1;
}
int consulta(trieNode* root,string key){
    int n = key.size();
    trieNode* S =root;
    int count=0;
    for(int i =0;i<n;i++){
        S = S->child[key[i]-'a'];
        if(S->ramas+S->end>1&& i!=n-1)count++;
    }
    return count;
}
int main(){
    int n;
    string s;
    while(cin>>n){
        trieNode* root=createNode();
        vector<string> dic(n);
        for(int i =0;i<n;i++){
            cin>>s;
            dic[i]=s;
            insert(root,s);
        }
        double ans=0;
        for(int i =0;i<n;i++){
            ans +=consulta(root,dic[i])+1;
        }
        cout<<fixed<<setprecision(2);
        cout<<ans/(n*1.0)<<endl;

    }
    return 0;
}