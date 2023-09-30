#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long double ld;
struct point{
    ld x, y;
};

struct all_{
    ld dist;
    int j,k;
    bool who;
};

bool comp(all_ a,all_ b){
    if(a.dist==b.dist){
        if(a.j==b.j)return a.k<b.k;
        else return a.j<b.j;
    }
    else return a.dist<b.dist;
}
ld dist(point a,point b){
    ld dx = a.x-b.x;
    ld dy = a.y-b.y;
    return (dx*dx)+(dy*dy);
}

const ld INF = 1000000000;
signed main(){__
	int n,m,o;
    cin>>n>>m>>o;
    vector<point> a(n);
    vector<point> b(m); 
    vector<point> p(o);
    for(auto &d:a)cin>>d.x>>d.y; 
    for(auto &d:b)cin>>d.x>>d.y; 
    for(auto &d:p)cin>>d.x>>d.y; 
    vector<bool> usedab(n);
    vector<bool> usedap(n);
    vector<bool> usedb(m);
    vector<bool> usedp(o);
    vector<all_>all_dist;
    for(int j = 0;j<m;j++)
        for(int k = 0;k<n;k++)
            all_dist.push_back({dist(b[j],a[k]),k,j,0});
    
    for(int j = 0;j<o;j++)
        for(int k = 0;k<n;k++)
            all_dist.push_back({dist(p[j],a[k]),k,j,1});
        
    sort(all_dist.begin(),all_dist.end(),comp);
    // qsort(all_dist.begin(),all_dist.end()comp);
    ld ans =0;
    for(int i = 0;i<all_dist.size();i++){
        // cout<<all_dist[i].dist<<" "<<all_dist[i].j<<" "<<all_dist[i].k<<" "<<all_dist[i].who<<endl;
        if(all_dist[i].who){
            if(usedap[all_dist[i].j]|| usedp[all_dist[i].k])continue;
            ans+=sqrt(all_dist[i].dist);
            usedap[all_dist[i].j] = true,usedp[all_dist[i].k] = true;
        }
        else{
            if(usedab[all_dist[i].j]|| usedb[all_dist[i].k])continue;
            ans+=sqrt(all_dist[i].dist);
            usedab[all_dist[i].j] = true,usedb[all_dist[i].k] = true;
        }
    

    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    return 0;
}  
