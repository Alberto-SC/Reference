#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

struct point{
    int x,w,id;
};

signed main(){__
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<point>points(m);
        for(int i = 0;i<m;i++){
            int x,w;
            cin>>x>>w;
            points[i] = {x,w,i+1};
        }
    
        sort(points.begin(),points.end(),[&](point a,point b){
            return a.w<b.w;
        });
        int ans = 0;
        vector<pair<int,int>> xs;
        for(int i = 0;i<2*n;i++)
            ans+=points[i].w,xs.push_back({points[i].x,points[i].id});
        
        sort(xs.begin(),xs.end());
        cout<<ans<<endl;
        for(int i = 0;i<n;i++){
            cout<<xs[i].second<<" "<<xs[(xs.size()-1)-i].second<<endl;
        }    
    }
}   