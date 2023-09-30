#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct Trie{
    Trie* childs[2];
    int val;
    int level;
};
Trie* create_node(){
    Trie* s = new Trie();
    s->childs[0] = s->childs[1] = NULL;
    s->level = 0;
    return s;
}
void insert(Trie *root,int key){
    Trie* s= root;
    for(int i = 30;i>=0;i--){
        bool b = (key>>i)&1;
        if(s->childs[b]== NULL)s->childs[b] = create_node();
        s = s->childs[b];
        s->level = i;
    }
    s->val = key;
}
int search_max(Trie *s,lli max){
    // cout<<max<<" "<<s->level<<endl;
    if(s->childs[0] != NULL && s->childs[1]!= NULL){
        // cout<<"Bifurcar"<<endl;
        int sum =  1<<s->childs[0]->level;
        max+=min(search_max(s->childs[0],max+sum),search_max(s->childs[1],max+sum));
    }
    else if(s->childs[0] != NULL || s->childs[1] != NULL){
        s->childs[0] == NULL?max+=search_max(s->childs[1],0):max+=search_max(s->childs[0],0);
    } 
    else return max;
    return max;
}
int main(){
    int n,x;
    cin>>n;
    Trie* root = create_node();
    for(int i = 0;i<n;i++){
        cin>>x;
        insert(root,x);
    }
    cout<<search_max(root,(lli)0);
    return 0;
}