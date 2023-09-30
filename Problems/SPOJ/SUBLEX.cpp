#include <bits/stdc++.h>
using namespace std;
const int maxn = 800000;
const int inf = 1e9;
map<int,int> to[maxn];
int len[maxn],start[maxn],link[maxn],subs[maxn];
int node,remaind;
int sz = 1,n = 0;
char s[maxn];
int make_node(int _pos,int _len){
    start[sz] = _pos;
    len[sz] = _len;
    return sz++;
}
void go_edge(){
    while(remaind>len[to[node][s[n-remaind]]]){
        node = to[node][s[n-remaind]];
        remaind -= len[node];
    }
}
void add_letter(int c){
    s[n++] = c;
    remaind++;
    int last = 0;
    while(remaind>0){
        go_edge();
        int edge = s[n-remaind];
        int &v = to[node][edge];
        int t = s[start[v]+remaind-1];
        if(v == 0){
            v = make_node(n-remaind,inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c){
            link[last = node];
            return;
        }
        else {
            int u = make_node(start[v],remaind-1);
            to[u][c] = make_node(n-1,inf);
            to[u][t] = v;
            start[v]+= remaind-1;
            len[v] -=remaind-1;
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
int dfsmark(int node,char a){
    // cout<<"Node: "<<node<<"  "<<a<<endl;
    for(auto c:to[node]){
        int childs =dfsmark(c.second,c.first);  
        if(len[c.second]<=n)subs[node]+=len[c.second];   
        // cout<<"childs "<<childs<<endl;
        subs[node] +=childs;
    }
    // cout<<"  "<<subs[node]<<endl;
    return subs[node]>0?subs[node]:min((n-start[node])-1,len[node]);
}
void dfs_print(int node,char a){
    cout<<node<<"  "<<a<<"   "<<subs[node]<<endl;
    for(auto c:to[node])
        dfs_print(c.second,c.first);
    
}
string a;
void dfssearch(int node,int k,int count){
    // cout<<"NODE: "<<node<<"  "<<count<<endl;
    for(auto c:to[node]){
        // cout<<"check child  "<<(char)c.first<<"  "<<count<<endl;
        if(len[c.second]>n){
            // cout<<endl<<count<<"  "<<n-start[c.second]-1<<endl;
            // cout<<"IF  "<<(n-start[c.second]-1)+count<<endl;
            if(k<(n-start[c.second]-1)+count){cout<<(a.substr(start[c.second],(k+1)-count).c_str());return;}
            count+=(n-start[c.second]-1);
        } 
        else{
            // cout<<"  "<<subs[c.second]+len[c.second]+count<<endl;
            if(k< len[c.second]+count){cout<<a.substr(start[c.second],(k+1)-count).c_str();return;}
            else if(k<subs[c.second]+len[c.second]+count){
                // cout<<"HOLA"<<endl;
                cout<<a.substr(start[c.second],len[c.second]).c_str();
                dfssearch(c.second,k,count+len[c.second]);
                return;
            }
            else 
                count+=len[c.second]+subs[c.second];
        }
    }
    // cout<<a.substr(0,a.size()-1)<<endl;
}
int main(){
    int q,x;
    cin>>a;
    a+="$";
    len[0] = inf;
    for(int i = 0;i<a.size();i++)
        add_letter(a[i]);
    cin>>q;
    dfsmark(0,'0');
    for(int i = 0;i<q;i++){
        cin>>x;
        dfssearch(0,x-1,0);
        cout<<endl;
    }
    return 0;
}