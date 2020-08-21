#include <bits/stdc++.h>
using namespace std;
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
        // cout<<"MAYOR"<<endl;
        node = to[node][s[n - remaind]];
        remaind -= len[node];
    }
}
 
void add_letter(int c){
    s[n++] = c;
    remaind++;
    // cout<<"suffix  "<<remaind<<"   "<<s[n-1]<<endl;
    int last = 0;
    while(remaind > 0){
        go_edge();
        int edge = s[n - remaind];
        int &v = to[node][edge];
        // cout<<v<<"   "<<start[v]<<"  "<<(char)edge<<"  "<<remaind<<endl;
        int t = s[start[v] + remaind - 1];
        // cout<<(char)t<<endl;
        if(v == 0){
            // cout<<"if"<<endl;
            v = make_node(n - remaind, inf);
            // cout<<" "<<v<<endl;
            link[last] = node;
            last = 0;
        }
        else if(t == c){
            // cout<<"else if"<<endl;
            link[last] = node;
            return;
        }
        else{
            // cout<<"else"<<endl;
            int u = make_node(start[v], remaind - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            start[v] += remaind - 1;
            len [v] -= remaind - 1;
            // cout<<len[v]<<endl;
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
 
// void setSuffixIndexByDFS(int node, int labelHeight){ 
//     if (n == NULL)  return; 
//     // if (n->start != -1) 
//         // print(n->start, *(n->end));    
//     int leaf = 1; 
//     int i; 
//     for (i = 0; i < MAX_CHAR; i++) { 
//         if (n->children[i] != NULL) { 
//             if (leaf == 1 && n->start != -1) 
//                 printf(" [%d]\n", n->suffixIndex); 
//             leaf = 0; 
//             setSuffixIndexByDFS(n->children[i], labelHeight + 
//                                   edgeLength(n->children[i])); 
//         } 
//     } 
//     if (leaf == 1){ 
//         n->suffixIndex = size - labelHeight; 
//         printf(" [%d]\n", n->suffixIndex); 
//     } 
// } 

bool dfsForPrint(int node,char edge){
    if(node != 0)
        // cout<<edge<<"   "<<node<<"  "<<len[node]<<"  "<<start[node]<<endl;
    for(auto c:to[node])
        dfsForPrint(c.second,c.first);
    
    return 0 ;
}
int main(){
    clock_t begin = clock();
    len[0] = inf;
    string s = "abcabxabcd";
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
        add_letter(s[i]);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(15)<<time_spent<<endl;
    // for(int i = 1; i < sz; i++)
        // ans += min((int)s.size() - start[i], len[i]);
    // cout << ans << "\n";
    return 0;
}