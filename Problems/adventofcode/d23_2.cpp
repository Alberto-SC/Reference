#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct lista {
    lli value;
    lista* next {NULL};
};

int main(){
    string s;
    cin>>s;
    vector<lista*> index(1000000);
    vector<lista> nodes(1000000);
    for (int i = 0;i<s.size();i++){
        nodes[i] = {s[i]-'0',NULL};
        index[nodes[i].value] = &nodes[i];
        if(i)
            nodes[i - 1].next = &nodes[i];
    }
    for (int i = s.size();i<1000000;i++){
        nodes[i] = {i+1,NULL};
        index[nodes[i].value] = &nodes[i];
        if(i)
            nodes[i - 1].next = &nodes[i];
    }
    nodes.back().next = &nodes[0];
    array<int,3>pick;
    lista *p = &nodes[0], *q = NULL, *r = NULL;
    clock_t begin = clock();
    for(int i = 0;i<10000000;i++){
        q = p->next;
        pick[0] = q->value, q = q->next;
        pick[1] = q->value, q = q->next;
        pick[2] = q->value;
        int dest = p->value - 1; 
        if(dest==0) 
            dest = 1000000;
        while(find(pick.begin(), pick.end(), dest) != pick.end()){
            dest--;
            if(dest ==0)
                dest = 1000000;
        }
        r = index[dest];
        lista* aux = p->next;
        p->next = q->next;
        q->next = r->next;
        r->next = aux;
        p = p->next;
    }

    auto x = index[1];
    cout<<x->value<<" "<<x->next->value<<" "<<x->next->next->value<<endl;
    cout<<x->next->value*x->next->next->value<<endl;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<time_spent<<endl;
    return 0;
} 