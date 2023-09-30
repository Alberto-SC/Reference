#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

const int maxn = 1000000;
constexpr int K = 30;
char start = 'a';
int nextNode[maxn][K];
int terminal_idx[maxn];
int terminal[maxn];
int Suffixlink[maxn];
int next_terminal[maxn];
int mpG[maxn];
int node[maxn];
int key = 0,V = 1;
void add_string(string &s, int idx) {
    int v = 0;
    for (char ch : s) {
        int c = ch - start;
        if (!nextNode[v][c]) 
            nextNode[v][c] = V++;
        v = nextNode[v][c];
    }
    mpG[v] = key++;
    node[idx+1] = v;
    terminal[v] = true;
    terminal_idx[v] = idx;
}

void push_links() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        auto& Slink = Suffixlink[v];
        q.pop();
        next_terminal[v] = terminal[Slink]? Suffixlink[v]: next_terminal[Slink];

        for (int c = 0; c < K; c++) {
            if (nextNode[v][c]) {
                Suffixlink[nextNode[v][c]]  = v? nextNode[Slink][c]:0;
                q.push(nextNode[v][c]);
            } else {
                nextNode[v][c] = nextNode[Slink][c]; 
            }
        }
    }
}
const int N = 100000;

vector<int> graph[N];
vector<int> bit;


int Start[N];
int End[N];
int pos= 0;

void dfs(int u){
    Start[u] = pos++;
    for(auto v:graph[u]){dfs(v);}
    End[u] = pos++;
}
void add(int idx,int x){
    for(++idx;idx<pos;idx+=idx&-idx)bit[idx]+=x;
}

int query(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}

int main(){__
    int n,k;
    cin>>k>>n;
    clock_t begin = clock();
    vector<string> S(n);
    mpG[0] = key++;
    for(int i= 0;i<n;i++){
        cin>>S[i];
        add_string(S[i],i);
    }
    // cout<<V<<" "<<pos<<endl;
    push_links();

    
    for(int i = 1;i<V;i++){
        if(terminal[i]){
            graph[mpG[next_terminal[i]]].push_back(mpG[i]);
        }
    }

    dfs(0); 
    bit.resize(pos);
    for(int i = 1;i<=n;i++){
        add(Start[i],+1);
        add(End[i],-1);
    }
    string s,text;
    for(int i = 0;i<k;i++){
        cin>>s;
        text = s.substr(1);
        if(s[0]=='?'){
            int ans = 0,v = 0;
            for(int j = 0;j<text.size();j++){
                v = nextNode[v][text[j]-start];
                int u = terminal[v]?v:next_terminal[v];
                ans+=query(Start[mpG[u]]);
            }
            // cout<<ans<<endl;
        }
        else if(s[0]=='-'){
            int idx = stoll(text);
            if(terminal[node[idx]]){
                add(Start[idx],-1);
                add(End[idx],+1);
            }
            terminal[node[idx]] = false;
        }
        else if(s[0]=='+'){
            int idx = stoll(text);
            if(!terminal[node[idx]]){
                add(Start[idx],+1);
                add(End[idx],-1);
            }
            terminal[node[idx]] =  true;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<time_spent<<endl;
}