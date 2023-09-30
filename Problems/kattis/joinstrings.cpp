#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct lista{
    int val;
    lista *last = this;
    lista *prev = NULL,*next = NULL;
    lista(int val):val(val){}
};

signed main(){__
	int t= 1,n,u,v;
    cin>>n;
    vector<string> s(n);
    for(auto &c:s)cin>>c;
    vector<lista*> pointers(n);
    for(int i = 0;i<n;i++)
        pointers[i] = new lista(i);

    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
        pointers[u]->last->next = pointers[v];
        pointers[v]->prev = pointers[u]->last->next;
        pointers[u]->last =pointers[v]->last;
    }
    for(int i = 0;i<n;i++){
        if(pointers[i]->prev==NULL){
            lista *current = pointers[i];
            while(current->next!=NULL){
                cout<<s[current->val];
                current = current->next;
            }
            cout<<s[current->val]<<endl;
            break;
        }
    }
    return 0;
}  
