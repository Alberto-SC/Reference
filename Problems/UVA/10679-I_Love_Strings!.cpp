#include <bits/stdc++.h>
using namespace std;
#define fpos adla
const int inf = 1e9;
const int maxn = 1e6  ;
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
    n++;
    remaind++;
    // cout<<"suffix  "<<remaind<<"   "<<s[n-1]<<endl;
    int last = 0;
    while(remaind > 0){
        go_edge();
        int edge = s[n - remaind];
        int &v = to[node][edge];
        // cout<<v<<"   "<<fpos[v]<<"  "<<(char)edge<<"  "<<remaind<<endl;
        int t = s[fpos[v] + remaind - 1];
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
            int u = make_node(fpos[v], remaind - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            fpos[v] += remaind - 1;
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
bool dfs(int node,string key,int check){
    if(node == 0){
        if(to[0].find(key[0])== to[0].end())return false;
        else return dfs(to[0][key[0]],key,0);
    }
    else{
        if(len[node]>=key.size()-check){
            // cout<<"IF"<<endl;
            if(s.substr(fpos[node],key.size()-check) == key.substr(check))return true;
            else return false;
        }
        else{
            // cout<<"ELSE"<<endl;
            if(s.substr(fpos[node],len[node]) == key.substr(check,len[node])){
                // cout<<"ELSE IF"<<endl;
                // cout<<len[node]<<"  "<<fpos[node]<<"   "<<s.substr(fpos[node],len[node])<<"   "<<key.substr(check,len[node])<<endl;
                if(to[node].find(key[check+ len[node]])!= to[node].end())
                    return dfs(to[node][key[check+len[node]]],key,check+len[node]);
                else return false;
            }
            else return false;
        }
    }

}
bool dfsForPrint(int node,char edge){
    if(node != 0)
        cout<<edge<<"   "<<node<<"  "<<len[node]<<"  "<<fpos[node]<<endl;
    for(auto c:to[node])
        dfsForPrint(c.second,c.first);
    
    return 0 ;
}
int main(){
    clock_t begin = clock();
    int t,q;
    cin>>t;
    while(t--){
        // cout<<"T: "<<t<<endl;
        cin>>s;
        cin>>q;
        vector<string> queries(q);
        for(auto &x:queries)cin>>x;
        for(int i = 0;i<s.size();i++){
            len[i] = 0;
            to[i].clear();
            fpos[i] = 0;
            link[i] = 0;
        }
        node = 0;
        remaind = 0;
        sz = 1;
        n = 0;
        len[0] = inf;
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
            add_letter(s[i]);
        // dfsForPrint(0,'0');
        for(int i = 0; i<q;i++){
            // cout<<queries[i]<<endl;
            if(dfs(0,queries[i],0))cout<<"y"<<endl;
            else cout<<"n"<<endl;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(15)<<time_spent<<endl;
    return 0;
}