#include <bits/stdc++.h>
using namespace std;
#define fpos adla
const int inf = 1e9;
const int maxn = 1e6;
string s;
map<int, int> to[maxn];
int len[maxn], fpos[maxn], link[maxn];
int node, remaind;
int sz = 1, n = 0;
 
int make_node(int _pos, int _len){
    fpos[sz] = _pos;
    len [sz] = _len;
    return sz++;
}
 
void go_edge(){
    while(remaind > len[to[node][s[n - remaind]]]){
        node = to[node][s[n - remaind]];
        remaind -= len[node];
    }
}
 
void add_letter(int c){
    s[n++] = c;
    remaind++;
    int last = 0;
    while(remaind > 0)
    {
        go_edge();
        int edge = s[n - remaind];
        int &v = to[node][edge];
        int t = s[fpos[v] + remaind - 1];
        if(v == 0)
        {
            v = make_node(n - remaind, inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c)
        {
            link[last] = node;
            return;
        }
        else
        {
            int u = make_node(fpos[v], remaind - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            fpos[v] += remaind - 1;
            len [v] -= remaind - 1;
            v = u;
            link[last] = u;
            last = u;
        }
        if(node == 0)
            remaind--;
        else
            node = link[node];
    }
}
 
int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin >> s;
        node = 0;
        remaind = 0;
        n = 0;
        sz = 1;
        for(int i = 0;i<4*s.size();i++){
            to[i].clear();
            len[i] = 0;
            fpos[i] = 0;
            link[i] = 0;
        }
        len[0] = inf;
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
            add_letter(s[i]);
        for(int i = 1; i < sz; i++)
            ans += min((int)s.size() - fpos[i], len[i]);
        cout<<ans<<endl;
    }
}
 