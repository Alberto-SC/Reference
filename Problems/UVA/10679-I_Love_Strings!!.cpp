#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


const int k =60;
char start = 'A';
const int maxn = 2000000;
int go_state[maxn][k];
int nxt[maxn][k];
bool leaf[maxn];
int link[maxn];
int exitLink[maxn];
vector<int> ids[maxn];
char pch[maxn];
int p[maxn];

int key = 0;

int new_node(int v,char c){
    p[key] =v;
    pch[key] = c;
    return key++;
}
void add_string(string s,int id){
    int v = 0;
    for(auto c:s){
        int id = c-start;
        if(nxt[v][id]==-1)nxt[v][id] = new_node(v,c);
        v = nxt[v][id];
    }
    leaf[v] = true;
    ids[v].push_back(id);
}

int go(int v,char c);

int get_link(int v){
    if(link[v] ==-1){
        if(v ==0 || p[v] == 0)
            link[v] = 0;
        else 
            link[v]  = go(get_link(p[v]),pch[v]);
    }
    return link[v];
}

int go(int v,char c){
    int id = c-start;
    if(go_state[v][id]==-1){
        if(nxt[v][id]!=-1)go_state[v][id] = nxt[v][id];
        else go_state[v][id] = v==0?0:go(get_link(v),c);
    }
    return go_state[v][id];
}

int get_exit_link(int v){
    if(v==0)return exitLink[v] = 0;
    if(exitLink[v]==-1){
        exitLink[v] = get_exit_link(link[v]);
    }
    return leaf[v]?v:exitLink[v];
}

void clean(int N){
    for(int i = 0;i<N;i++){
        exitLink[i] = -1;
        link[i] = -1;
        leaf[i] = false;
        ids[i].clear();
        for(int j = 0;j<k;j++)
            go_state[i][j] = -1,nxt[i][j] = -1;
    }
}

signed main(){__
    int t;
    cin>>t;
    clean(maxn);
    while(t--){
        key = 0;
        new_node(-1,'$');
        int q;
        string s,str;
        cin>>s;
        cin>>q;
        vector<string> S(q);    
        vector<bool> ans(q);
        for(int i = 0;i<q;i++)
            cin>>S[i],add_string(S[i],i);

        for(int i = 0;i<key;i++)
            get_link(i);
        for(int i = 0;i<key;i++)
            get_exit_link(i);

        int v = 0;
        vector<bool> vis(key);
        vis[0] = true;
        for(int i = 0;i<s.size();i++){
            v = go(v,s[i]);
            int u = v;
            if(!vis[u]){
                while(u){
                    vis[u] = true;
                    for(auto c:ids[u])
                        ans[c] = true; 
                    u = exitLink[u];
                }
            }
        }

        for(int i = 0;i<q;i++){
            if(ans[i])cout<<"y"<<endl;
            else cout<<"n"<<endl;
        }
        clean(key);
    
    }
    return 0;
}