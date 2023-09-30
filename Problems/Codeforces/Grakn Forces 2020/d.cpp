#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define x first
#define y second  n 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,k,m;
    while(t--){
        cin>>n>>m;
        vector<pair<int,int>> c(m);
        vector<pair<int,int>> r(n);
        for(int i = 0;i<n;i++)
            cin>>r[i].x>>r[i].y;
        for(int i = 0;i<m;i++)
            cin>>c[i].x>>c[i].y;
        int mx= 0,idx ;
        pair<int,int> mxp;
        for(int i = 0;i<n;i++){
            pair<int,int> point = r[i];
            for(int j = 0;j<m;j++){
                if(c[j].x>=point.x && c[j].y>=point.y){
                    if(c[j].x-point.x <= c[j].y-point.y){
                        point.x = c[j].x+1;
                    }
                    else 
                        point.y = c[j].y+1;
                }
           
            }
            if(point.x-r[i].x + point.y-r[i].y> mx){
                mx = point.x-r[i].x + point.y-r[i].y;
                mxp = point;
                idx = i;
            }
        }
        // cout<<r[idx].x<<" "<<r[idx].y<<endl;
        // cout<<mxp.x<<" "<<mxp.y<<endl;
        int ans = mx;
        if(mx != 0){
        pair<int,int> copy = r[idx];
            for(int i = 0;i<n;i++){
                r[i].x+= mxp.x-copy.x;
                r[i].y+= mxp.y-copy.y;
            }
        }
        mx = 0;

        for(int i = 0;i<n;i++){
            pair<int,int> point = r[i];
            for(int j = 0;j<m;j++){
                if(c[j].x>=point.x && c[j].y>=point.y){
                    if(c[j].x-point.x < c[j].y-point.y){
                        point.x = c[j].x+1;
                    }
                    else 
                        point.y = c[j].y+1;
                }
        
            }
            if((point.x-r[i].x) + (point.y-r[i].y)> mx){
                mx = point.x-r[i].x + point.y-r[i].y;
                mxp = point;
                idx = i;
            }
        }
        ans+=mx;          
        cout<<ans<<endl;    
    }
    return 0;
}

