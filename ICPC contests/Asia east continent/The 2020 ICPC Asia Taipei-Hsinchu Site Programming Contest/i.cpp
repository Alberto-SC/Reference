#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> parent(maxn,-1),low(maxn,1e9),d(maxn,-1);
vector<bool> vis(maxn);
int Time = 0;
typedef pair<int,int> edge;
vector<edge> st;
vector<vector<edge>> comps;

void output_comp(int u,int v){
    vector<edge> comp;
    edge e;
    do{
        e = st.back();
        st.pop_back();
        comp.push_back(e);
    }while(!(e.first== u && e.second ==v));
    comps.push_back(comp);
    cout<<"COMP: "<<endl;
    for(auto c:comp)cout<<c.first<<" "<<c.second<<endl;
    cout<<"end"<<endl;
}

vector<vector<int>> ncomps;
void node_comps(){
    for(int i = 0;i<comps.size();i++){
        vector<int> ncomp;
        for(int j = 0;j<comps[i].size();j++){
            ncomp.push_back(comps[i][j].first);
            ncomp.push_back(comps[i][j].second);
        }
        sort(ncomp.begin(),ncomp.end());
        ncomp.erase(unique(ncomp.begin(),ncomp.end()),ncomp.end());
        ncomps.push_back(ncomp);
    }
}

void dfs(int u){
    vector<pair<int,int>> call_stack;
    call_stack.push_back({u,(-1)<<1});
    while(!call_stack.empty()){
        pair<int,int> curr = call_stack.back();
        call_stack.pop_back();
        int u = curr.first;
        int idx = curr.second>>1;
        int remain = curr.second&1;
        cout<<u<<" "<<idx<<" "<<remain<<" "<<curr.second<<endl;
        if(idx == -1){
            vis[u] = true;
            d[u] = ++Time;
            call_stack.push_back({u,0});   
        }
        else if(idx<graph[u].size()){
            int v = graph[u][idx];
            cout<<"v: "<<v<<endl;
            if(remain){
                cout<<"REMAIN: "<<low[v]<<" "<<d[u]<<endl;
                if(low[v]>= d[u])output_comp(u,v);
                low[u] = min(low[u],low[v]);
                call_stack.push_back({u,idx+1<<1});
            }
            else{
                if(!vis[v]){
                    cout<<"NO vis"<<endl;
                    st.push_back({u,v});
                    parent[v] = u;
                    call_stack.push_back({u,(idx<<1)|1});
                    call_stack.push_back({v,(-1)<<1});
                }
                else if(parent[u]!= v && d[v]<d[u]){
                    cout<<"No parent "<<low[u]<<" "<<d[v]<<endl;
                    st.push_back({u,v});
                    low[u] = min(low[u],d[v]);
                    call_stack.push_back({u,idx+1<<1});
                }
                else {
                    cout<<"else "<<endl;
                    call_stack.push_back({u,idx+1<<1});
                }
            }
        }
    }
}
vector<int> artic_idx(maxn);
vector<int> component(maxn);
vector<bool> is_artic(maxn);
vector<int> ADJ[maxn];
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0;i<n;i++)
        if(!vis[i])
            dfs(i);
    node_comps();
    for(int i = 0;i<n;i++)
        artic_idx[i] =component[i] = -1;

    for(int idx = 0;idx<ncomps.size();idx++){
        for(int nb = 0;nb<ncomps[idx].size();nb++){
            int i = ncomps[idx][nb];
            if(component[i]!= -1 && component[i]!= idx){
                is_artic[i] = true;
            }
            component[i] = idx;
        }
    }
    vector<int> artics;
    for(int i = 0;i<n;i++){
        if(is_artic[i]){
            artic_idx[i] = artics.size();
            artics.push_back(i);
        }
    }
    int A = artics.size();
    int C = comps.size();
    int N = A+C;
    for(int idx = 0;idx<ncomps.size();idx++){
        for(int nb = 0;nb<ncomps[idx].size();nb++){
            int i = ncomps[idx][nb];
            if(is_artic[i]){
                ADJ[A+idx].push_back(artic_idx[i]);
                ADJ[artic_idx[i]].push_back(A+idx);
            }
        }
    }
    for(int i = 0;i<N;i++){
        vis[i] = false;
        sort(ADJ[i].begin(),ADJ[i].end());
        ADJ[i].erase(unique(ADJ[i].begin(),ADJ[i].end()),ADJ[i].end());
    }
    cout<<"ADJ"<<endl; 
    for(int i = 0;i<n;i++){
        for(auto v:ADJ[i]){
            cout<<i<<" "<<v<<endl;
        }
    }
    cout<<endl;
    vector<vector<int>> X;
    // for(int i = 0;i<n;i++){
    //     if(is_artic[i]){
    //         X[artic_idx[i]].push_back(x[i]);
    //     }
    //     else if(comp_idx[i]!= -1){
    //         X[A+comp_idx[i]].push_back(x[i]);
    //     }
    // }
    return 0;
}