#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> d(maxn);
vector<int> s(maxn);
vector<int> e(maxn);
vector<int> st[2];
vector<int> lazy[2];
int idx;
void dfs(int u,int p = -1,int dist = 0){
    d[u] = dist;
    s[u] = idx;
    for(auto v:graph[u]){
        if(v ==p)continue;
        idx++;
        dfs(v,u,dist+1);
    }
    e[u] = idx;
}

int n; 

void propagate(int v,int l,int r,int who){
    if(lazy[who][v] == 0)return;
    st[who][v] += lazy[who][v]* ((r-l)+1);
    if(l!=r){
        lazy[who][v<<1] += lazy[who][v];
        lazy[who][v<<1|1] += lazy[who][v];
    }
    lazy[who][v] =0;
}
void update(int l,int r,int x,int who,int v = 1,int sl = 0,int sr = n-1){
    // cout<<l<<" "<<r<<" "<<sl<<" "<<sr<<endl;
    propagate(v,sl,sr,who);
    if(sl>sr || sr<l || sl>r)return ;
    if(sl>=l && sr<=r){
        lazy[who][v] += x;
        propagate(v,sl,sr,who);
        return;
    }
    int mid = (sl+sr)>>1;
    update(l,r,x,who,v<<1,sl,mid);
    update(l,r,x,who,v<<1|1,mid+1,sr);
    st[who][v] = st[who][v<<1] + st[who][v<<1|1];    
}

int query(int l,int r,int who,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr,who);
    if(sl>sr || sr<l || sl>r)return 0;
    if(sl>=l && sr<=r){
        return st[who][v];
    }
    int mid = (sl+sr)>>1;
    return query(l,r,who,v<<1,sl,mid)+query(l,r,who,v<<1|1,mid+1,sr);
}
void print(){
    for(int i = 0;i<n;i++){
        if(d[i]&1)cout<<query(s[i],s[i],1)<<" ";
        else cout<<query(s[i],s[i],0)<<" ";
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<query(s[i],s[i],1)<<" ";
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<query(s[i],s[i],0)<<" ";
    }
    cout<<endl<<endl;
}

int main(){
    int val,x,m,u,v,t   ;
    cin>>n>>m;
    st[0] = vector<int> (4*n,0);
    st[1] = vector<int> (4*n,0);
    lazy[0] = vector<int> (4*n,0);
    lazy[1] = vector<int> (4*n,0);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0);
    for(int i = 0;i<n;i++){
        if(d[i]&1){
            // cout<<s[i]<<" ";
            update(s[i],s[i],nums[i],1);
        }
        else{
            // cout<<s[i]<<" ";
            update(s[i],s[i],nums[i],0);
        }
    }
    // print();
    for(int i = 0;i<m;i++){
        cin>>t;
        if(t ==1){
            cin>>x>>val;
            x--;
            if(d[x]&1)
                update(s[x],e[x],val,1),update(s[x],e[x],-val,0);
            else   
                update(s[x],e[x],val,0),update(s[x],e[x],-val,1);
        }
        else{
            cin>>x;
            x--;
            if(d[x]&1)
                cout<<query(s[x],s[x],1)<<endl;
            else   
                cout<<query(s[x],s[x],0)<<endl;
        }
        // print();
    }
    return 0;
}