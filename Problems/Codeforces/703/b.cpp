#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL); 
signed main(){__
	int t= 1,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> p;
        vector<int> point[2];
        for(int i = 0;i<n;i++){
            cin>>x>>y;
            point[0].push_back(x);
            point[1].push_back(y);
            p.push_back({x,y});
        }
        for(int i = 0;i<2;i++)
            sort(point[i].begin(), point[i].end());
        int mx = 1,my = 1;
        if(n%2 ==0){ 
            mx = (point[0][n/2]-point[0][(n/2)-1])+1;
            my = (point[1][n/2]-point[1][(n/2)-1])+1;
        }
        cout<<mx*my<<endl;
    }
    return 0;
}  
