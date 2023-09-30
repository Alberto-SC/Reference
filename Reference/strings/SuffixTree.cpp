/**
 * Author: Alberto silva
 * Date: 2019-05-15
 * Source: https://e-maxx.ru/algo/ukkonen
 * Description: Ukkonen's algorithm for online suffix tree construction.
 *  Each node contains indices [l, r) into the string, and a list of child nodes.
 *  Suffixes are given by traversals of this tree, joining [l, r) substrings.
 *  The root is 0 (has l = -1, r = 0), non-existent children are -1.
 *  To get a complete tree, append a dummy symbol -- otherwise it may contain
 *  an incomplete path (still useful for substring matching, though).
 * Time: $O(26N)$
 * Status: stress-tested a bit
 */

const int inf = 1e9;
const int maxn = 1e6  ;
char s[maxn];
map<int, int> to[maxn];
int len[maxn], start[maxn], link[maxn];
int node, remaind;
int sz = 1, n = 0;
int make_node(int _pos, int _len){
    start[sz] = _pos;
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
    while(remaind > 0){
        go_edge();
        int edge = s[n - remaind];
        int &v = to[node][edge];
        int t = s[start[v] + remaind - 1];
        if(v == 0){
            v = make_node(n - remaind, inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c){
            link[last] = node;
            return;
        }
        else{
            int u = make_node(start[v], remaind - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            start[v] += remaind - 1;
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

bool dfsForPrint(int node,char edge){
    if(node != 0)
        cout<<edge<<"   "<<node<<"  "<<len[node]<<"  "<<start[node]<<endl;
    for(auto c:to[node])
        dfsForPrint(c.second,c.first);
    return 0 ;
}