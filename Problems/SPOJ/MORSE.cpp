#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int k = 2;
const int maxn = 1000007;
map<char,int> mp = {{'-',1},{'.',0}};

int nxt[maxn][k];
int go_state[maxn][k];
int link[maxn];
int exitLink[maxn];
bool leaf[maxn];    
int p[maxn];
int pch[maxn];
int ids[maxn];
int cont[maxn];
map<char,string> morse = {
    {'A', ".-"}, 
    {'B', "-..."}, 
    {'C', "-.-."}, 
    {'D', "-.."},
    {'E', "."},  
    {'F', "..-."}, 
    {'G', "--."}, 
    {'H', "...."}, 
    {'I', ".."}, 
    {'J', ".---"}, 
    {'K', "-.-"}, 
    {'L', ".-.."}, 
    {'M', "--"}, 
    {'N', "-."}, 
    {'O', "---"}, 
    {'P', ".--."}, 
    {'Q', "--.-"}, 
    {'R', ".-."}, 
    {'S', "..."}, 
    {'T', "-"} ,
    {'U', "..-"}, 
    {'V', "...-"}, 
    {'W', ".--"}, 
    {'X', "-..-"}, 
    {'Y', "-.--"}, 
    {'Z', "--.."}};

int key = 0;

int new_node(int v,int c){
    p[key] = v;
    pch[key] = c;
    return key++;
}

void add_string(string s,int id){
    int v = 0;
    for(auto c:s){
        for(auto x:morse[c]){
            if(nxt[v][mp[x]]==-1)nxt[v][mp[x]] = new_node(v,mp[x]);
            v = nxt[v][mp[x]];
        }
    }
    leaf[v] = true;
    ids[v] = id;
    cont[v]++;
}

int go(int v,int c);

int get_link(int v){
    if(link[v]==-1){
        if(v == 0|| p[v] == 0)link[v] =0;
        else link[v] = go(get_link(p[v]),pch[v]);
    }
    return link[v];
}

int go(int v,int c){
    if(go_state[v][c]==-1){
        if(nxt[v][c]!=-1)
            go_state[v][c] = nxt[v][c];
        else 
            go_state[v][c] = v==0?v:go(get_link(v),c);  
    }
    return go_state[v][c];
}

int get_exit_link(int v){
    if(v==0)return exitLink[v] = 0;
    if(exitLink[v] ==-1){
        exitLink[v] = get_exit_link(link[v]);
    }
    return leaf[v]?v:exitLink[v];
}

void clean(int N){
    for(int i =0 ;i<N;i++){
        nxt[i][0] = nxt[i][1] = -1;
        go_state[i][0] = go_state[i][1] = -1;
        link[i] = -1;
        exitLink[i] = -1;
        p[i] = -1;
        pch[i] = -1;
        leaf[i] = false;
        ids[i] = -1;
        cont[i] = 0;
    }   
}

signed main(){__
    int t,n;
    cin>>t;
    clean(maxn);
    while(t--){
        key = 0;
        new_node(-1,-1);
        string s,str;
        cin>>s;
        cin>>n;
        vector<string> S(n);
        vector<int> sizes(n);
        vector<vector<int>> ranges(s.size());
        for(int i = 0;i<n;i++){
            cin>>S[i];
            for(auto c:S[i])
                sizes[i]+=morse[c].size();
            add_string(S[i],i);
        }
        for(int i = 0;i<key;i++)
            get_link(i);
        for(int i = 0;i<key;i++)
            get_exit_link(i);
        int v = 0;
        vector<int> dp(s.size()+1);
        dp[s.size()]=1;
        for(int i = 0;i<s.size();i++){
            v = go(v,mp[s[i]]);
            int u = v;
            while(u){
                if(leaf[u])
                    for(int j = 0;j<cont[u];j++)
                        ranges[i-(sizes[ids[u]]-1)].push_back(i);
                u = exitLink[u];
            }
        }
        // for(int i = 0;i<s.size();i++){
        //     cout<<"L:"<<i<<"->";
        //     for(auto c:ranges[i])cout<<c<<" ";
        //     cout<<endl;
        // }
        for(int i = s.size()-1;i>= 0;i--){
            for(auto c:ranges[i])
                dp[i]+=dp[c+1];
        }
        cout<<dp[0]<<endl;
        clean(key);
    }
    return 0;
}