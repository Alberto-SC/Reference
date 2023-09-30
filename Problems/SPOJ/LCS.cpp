#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 1200000  ;
char s[maxn];
map<int, int> to[maxn];
int len[maxn], start[maxn], link[maxn],sindex[maxn],who[maxn];
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
int sa,sb;
void setSuffixIndex(int node, int labelHeight){ 
    for (auto c:to[node])  
        setSuffixIndex(c.second, labelHeight + min(n-start[c.second],len[c.second])); 
    if (len[node]>n && node !=0)
        sindex[node] = n - labelHeight; 
} 

int mark(int node){
    bool first = false,second = false;
    for(auto c:to[node]){
        if(len[c.second]>n){
            if(sindex[c.second]<sa)first =  true;
            else if(sindex[c.second]>=sa+1)second = true;
        }
        else {
            int result = mark(c.second);
            if(result == 3){second = true;first = true;}
            else if(result == 1)first = true;
            else if(result == 2)first = true;
        }
    }
    // if(who[node]==2)return who[node];
    if(first && second)return who[node]= 3;
    else if(first)return who[node] =1; 
    else if(second)return who[node] = 2; 
}
int ans = -1000;
int LCS(int node ,int length,char b){
    // cout<<length<<"  "<<b<<"   "<<who[node]<<endl;
    for(auto c:to[node]){
        if(who[c.second] == 3)LCS(c.second,length+ min(n-start[c.second],len[c.second]),c.first);
    }
    ans = max(ans,length);
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    clock_t begin = clock();
    string a,b;
    cin>>a>>b;
    sa = a.size();
    sb = b.size();
    a=a+"#"+b+"$";
    len[0] = inf;
    for(int i = 0;i<a.size();i++)
        add_letter(a[i]);
    setSuffixIndex(0,0);
    mark(0);
    LCS(0,0,'0');
    cout<<ans<<endl;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<time_spent<<endl;
    return 0;
}
