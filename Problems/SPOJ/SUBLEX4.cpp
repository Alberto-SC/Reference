#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 200000;
const int INF = 100000000;
struct node{
    node *p[26], *pre;
    int len, sons;
    node(){
        memset(p, 0, sizeof p);
        pre = NULL;
        len = 0; sons = 0;
    }
}Edges[MAXN*2+10], *ecnt=Edges+1,*root=Edges,*last=Edges, *st[MAXN*2+10];
void Insert(int w){
    node *np = ecnt++;
    node *p = last;
    np->len = p->len+1;
    while(p&&!p->p[w])
        p->p[w]=np, p=p->pre;
    if(!p){
        np->pre = root;
    }else{
        node *q = p->p[w];
        if(p->len+1 == q->len){
            np->pre = q;
        }else{
            node *nnd = ecnt++;
            memcpy(nnd->p, q->p, sizeof (nnd->p));
            nnd->len = p->len+1; nnd->pre = q->pre; q->pre = nnd; np->pre = nnd;
            while(p&&p->p[w]==q)
                p->p[w]=nnd, p=p->pre;
        }
    }
    last = np;
}
const int MAXT = 100000;
char s1[MAXT+10], s2[MAXT+10];
bool cmp(node *a, node *b){
    return a->len > b->len;
}
void Init(int ds){
    for(int i=0;i<ds;i++){
        st[i]->sons = 1;
        for(int j=0;j<26;j++)
            if(st[i]->p[j])
                st[i]->sons += st[i]->p[j]->sons;
    }
}
int main(){
    scanf("%s", s1);
    int l1 = strlen(s1), ans = 0;
    for(int i=0;i<l1;i++)
        Insert(s1[i]-'a');
    int ds = 0;
    for(node *p = &Edges[1];p!=ecnt;p++)
        st[ds++] = p;
    sort(st, st+ds, cmp);
    Init(ds);
    int q;
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        node *u = root;
        int k, tmp;
        scanf("%d", &k);
        while(k){
            for(int j=0;j<26;j++){
                if(u->p[j] && u->p[j]->sons < k) k -= u->p[j]->sons;
                else if(u->p[j]){
                    k--;
                    printf("%c", j+'a');
                    u = u->p[j];
                    break;
                }
            }
        }
        printf("\n");
    }

    return 0;
}