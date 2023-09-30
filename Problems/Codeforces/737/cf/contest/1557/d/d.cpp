#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
struct segment{
    int idx,l,r;
    bool operator<(segment B)const{
        if(idx==B.idx){
            if(l==B.l)
                return r<B.r;
            return l<B.l;
        }
        return idx<B.idx;
    }
    friend ostream& operator <<(ostream &out,const segment &S){
        out<<S.idx<<" "<<S.l<<" "<<S.r<<endl;
        return out;
    }
};

int key = 0;
map<segment,int> mp;
const int maxn = 600007;
vector<int> dp(maxn,-1);
vector<pair<int,int>> graph(maxn,{-1,-1});
int solve(int idx){
    int &x = dp[idx];
    if(x!= -1)return x;
    if(graph[idx].x == -1 && graph[idx].y ==-1){
        return dp[idx] = 1;
    }
    int ans ;
    if(graph[idx].y==-1)
        ans = solve(graph[idx].x);
    else if(graph[idx].x == -1)
        ans = solve(graph[idx].y)+1;
    else
        ans = max(solve(graph[idx].x),solve(graph[idx].y)+1);
    return x = ans;
}

vector<pair<int,int>> st;
vector<int> lazy;

int N;
void propagate(int l,int r,int v){
    if(lazy[v]==-1)return ;
    st[v].x = lazy[v];
    st[v].y = lazy[v];
    if(l!=r){
        lazy[v<<1] = lazy[v];
        lazy[v<<1|1] = lazy[v];
    }
    lazy[v] = -1;
}

void update(int l,int r,int x,int v = 1,int sl = 0,int sr = N-1){
    propagate(sl,sr,v);
    if(sl> r || sr <l|| sl>sr)return ;
    if(sl>=l && sr<=r){
        lazy[v] = x;
        propagate(sl,sr,v);
        return ;
    }
    int m = (sl+sr)>>1;
    update(l,r,x,v<<1,sl,m);
    update(l,r,x,v<<1|1,m+1,sr);
    st[v].x = min(st[v<<1].x,st[v<<1|1].x);
    st[v].y = max(st[v<<1].y,st[v<<1|1].y);
}

pair<int,int> query(int l,int r,int v = 1,int sl = 0,int sr = N-1){ 
    propagate(sl,sr,v);
    if(sl>r ||sr<l || sl>sr)return {1e14,-1e14} ;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    auto L = query(l,r,v<<1,sl,m);
    auto R = query(l,r,v<<1|1,m+1,sr);
    return {min(L.x,R.x),max(L.y,R.y)};
}

void print(){
    for(int i =0;i<N;i++)
        cout<<query(i,i).y<<" ";
    cout<<endl;
}
signed main(){__
	int t= 1,n,m;
    cin>>n>>m;
    vector<segment> sg(m);
    vector<pair<int,int>> rows[n];
    vector<int> _all;
    for(int i = 0;i<m;i++){
        cin>>sg[i].idx>>sg[i].l>>sg[i].r;
        sg[i].idx--;
        mp[sg[i]] = key++;
        _all.push_back(sg[i].l);
        _all.push_back(sg[i].r);
        rows[sg[i].idx].push_back({sg[i].l,sg[i].r});
    }
    sort(_all.begin(),_all.end());
    vector<int> u;
    int last = _all[0];
    u.push_back(last);
    for(int i = 0;i<_all.size();i++){
        if(_all[i]!=last){
            last = _all[i];
            u.push_back(last);
        }
    }   
    vector<int> dummy(n);
    N = u.size();
    lazy.resize(4*N,-1);
    st.resize(4*N,{n+1,n+1});
    for(int i = 0;i<n;i++){
        if(rows[i].size()==0)continue;
        sort(rows[i].begin(),rows[i].end());
        for(int j = 0;j<rows[i].size()-1;j++){
            int idx = mp[{i,rows[i][j].x,rows[i][j].y}];
            int idx2 = mp[{i,rows[i][j+1].x,rows[i][j+1].y}];
            graph[idx].x = idx2;
        }
    }
    for(int i = 0;i<n;i++){
        dummy[i] = key++;
        if(rows[i].size())
            graph[dummy[i]].x =mp[{i,rows[i][0].x,rows[i][0].y}];
    }
    for(int i= n-1;i>=0;i--){
        for(int j = 0;j<rows[i].size();j++){
            int l = lower_bound(u.begin(),u.end(),rows[i][j].x)-u.begin();
            int r = lower_bound(u.begin(),u.end(),rows[i][j].y)-u.begin();
            int idx = query(l,r).x;
            if(idx!=n+1){
                int idx2 =  mp[{i,rows[i][j].x,rows[i][j].y}];
                graph[idx2].y = dummy[idx];
            }   
        }
        for(int j = 0;j<rows[i].size();j++){
            int l = lower_bound(u.begin(),u.end(),rows[i][j].x)-u.begin();
            int r = lower_bound(u.begin(),u.end(),rows[i][j].y)-u.begin();
            update(l,r,i);
        }
    }
    for(int i = 0;i<key;i++)
        solve(i);
    int mx = *max_element(dp.begin(),dp.end()),idx;
    for(int i = 0;i<n;i++){
        if(dp[dummy[i]]==mx){
            idx = i;
            break;
        }
    }
    last = idx;
    vector<int> erase;
    update(0,N-1,-2);
    for(int j = 0;j<rows[idx].size();j++){
        int l = lower_bound(u.begin(),u.end(),rows[idx][j].x)-u.begin();
        int r = lower_bound(u.begin(),u.end(),rows[idx][j].y)-u.begin();
        update(l,r,idx);
    }
    for(int i = 0;i<idx;i++)
        erase.push_back(i+1);
    int aux = mx;
    for(int i = 0;i<n;i++)
        cout<<dp[dummy[i]]<<" ";
    cout<<endl;

    for(int i = idx+1;i<n;i++){
        if(mx ==1){
            erase.push_back(i+1);
            continue;
        };
        if(dp[dummy[i]]==mx-1){
            bool flag = false;
            for(int j = 0;j<rows[i].size();j++){
                int l = lower_bound(u.begin(),u.end(),rows[i][j].x)-u.begin();
                int r = lower_bound(u.begin(),u.end(),rows[i][j].y)-u.begin();
                int idx = query(l,r).y;
                if(idx == last)
                    flag =true;
            }
            if(flag){
                last = i;
                mx--;
                for(int j = 0;j<rows[i].size();j++){
                    int l = lower_bound(u.begin(),u.end(),rows[i][j].x)-u.begin();
                    int r = lower_bound(u.begin(),u.end(),rows[i][j].y)-u.begin();
                    update(l,r,i);
                }
            }
            else    
                erase.push_back(i+1);

        }
        else 
            erase.push_back(i+1);
    }
    if(n == 68166)
        cout<<aux<<endl;
    cout<<erase.size()<<endl;
    for(auto c:erase)cout<<c<<" ";
    return 0;
}  
