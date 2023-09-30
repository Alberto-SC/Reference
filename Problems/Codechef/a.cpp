#include <bits/stdc++.h>
using namespace std;
struct trie{   
    int d;
    trie childrens[10];
    insert(string a){
        for(int i = 0;i<a.size();i++){
            if(this->childrens[a[i]-'0']== null){
                this->childrens[a[i]-'0'] = createNode();
            }
            else this = this->childrens[a[i]-'0'];
        }

    }
    trie createNode(){
        trie = new trie();
        for(int i = 0;i<10;i++){
            this.children[i] =  null;
        }
        return trie;
    }
    search(string a){
        for(int i = 0,i<a.size();i++){
            if(this.chilrens[a[i]-'0'] == NULL)return 0;
        }
        return 1;
    }
}

int main(){

    return 0;
}