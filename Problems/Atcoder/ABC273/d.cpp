#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,N,Q,a,b,m,x,y;
    cin>>n>>m>>x>>y;
    cin>>N;
    x--,y--;
    map<int,vector<int>> L;
    map<int,vector<int>> R;
    map<int,vector<int>> U;
    map<int,vector<int>> D;
    for(int i = 0;i<N;i++){
        cin>>a>>b;
        a--,b--;
        L[a].push_back(b);
        R[a].push_back(b);
        U[b].push_back(a);
        D[b].push_back(a);
    }
    for(auto &c:L){
        c.second.push_back(-1);
        sort(c.second.rbegin(),c.second.rend());
    }
    for(auto &c:R){
        c.second.push_back(m);
        sort(c.second.begin(),c.second.end());
    }
    for(auto &c:U){
        c.second.push_back(-1);
        sort(c.second.rbegin(),c.second.rend());
    }
    for(auto &c:D){
        c.second.push_back(n);
        sort(c.second.begin(),c.second.end());
    }


    cin>>Q;
    while(Q--){
        char t;
        int l;
        cin>>t>>l;
        if(t == 'U'){
            if(!U.count(y))U[y].push_back(-1);
            int nxt = upper_bound(U[y].begin(),U[y].end(),x,greater<int>())-U[y].begin();
            
            int dist = (x-U[y][nxt])-1;
            l = min(l,dist);
            x-=l;
        }
        else if(t == 'D'){
            if(!D.count(y))D[y].push_back(n);
            int nxt = upper_bound(D[y].begin(),D[y].end(),x)-D[y].begin();
            // cout<<x<<" "<<y<<endl;
            // cout<<D[y][nxt]<<" "<<D[y].size()<<" "<<nxt<<" "<<D[y][0]<<endl;
            int dist = (D[y][nxt]-x)-1;
            l = min(l,dist);
            x+=l;
        }
        else if(t== 'L'){
            if(!L.count(x))L[x].push_back(-1);
            int nxt = upper_bound(L[x].begin(),L[x].end(),y,greater<int>())-L[x].begin();
            int dist = (y-L[x][nxt])-1;
            l = min(l,dist);
            y-=l;
        }
        else{
            if(!R.count(x))R[x].push_back(m);
            int nxt = upper_bound(R[x].begin(),R[x].end(),y)-R[x].begin();
            int dist = (R[x][nxt]-y)-1;
            l = min(l,dist);
            y+=l;
        }
        cout<<x+1<<" "<<y+1<<endl;
    }
    return 0;
}