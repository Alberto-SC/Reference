#include <bits/stdc++.h>
using namespace std;
int n,m,q,k;
vector<int> wu;
struct Trie{
    Trie *childs[2];
    int cant;
    int level;
};
Trie* createNode(){
    Trie* s = new Trie();
    s->childs[0] = s->childs[1] = NULL;
    s->cant = 0;
    s->level = -1;
    return s;
}
void insert(Trie*root,string key){
    Trie *s = root;
    for(int i = 0;i<n;i++){
        bool b = key[i] == '1';
        if(s->childs[b]==NULL)s->childs[b] = createNode();
        s = s->childs[b];
        s->level = i;
    }
    s->cant++;
}
int dfs(Trie*root,string key,int here,int how){
    // cout<<root->level<<"    "<<here<<"  "<<how<<"   "<<k<<endl;
    int c1= 0,c2 = 0;
    if(here>k)return 0;
    if(root->childs[0]==NULL && root->childs[1]== NULL)return root->cant;
    bool val = key[root->level+1] == '1';
    // cout<<"VAL "<<val<<endl;
    if(root->childs[val]!= NULL)c1=dfs(root->childs[val],key,here+wu[root->level+1],how);
    if(root->childs[!val]!= NULL)c2=dfs(root->childs[!val],key,here,how);
    // cout<<how<<endl;
    return c1+c2;
}
int main(){
    ios_base::sync_with_stdio(0);
    string s;
    cin>>n>>m>>q;
    wu.resize(n);
    Trie* root = createNode();
    for(auto &x:wu)cin>>x;
    for(int i = 0;i<m;i++){
        cin>>s;
        insert(root,s);
    }
    for(int i = 0;i<q;i++){
        cin>>s>>k;
        if(accumulate(wu.begin(),wu.end(),0)<k)cout<<m<<endl;
        else
            cout<<dfs(root,s,0,0)<<endl;
        // cout<<"________________"<<endl;
    }

    return 0;
}