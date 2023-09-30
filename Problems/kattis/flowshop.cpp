#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
signed main(){__
	int t= 1,n,m;
    cin>>n>>m;
    vector<vector<int>> M(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
        }
    }
    vector<vector<pair<int,int>>> order(m+1);
    for(int i = 0;i<n;i++)
        order[0].push_back({M[i][0],0});

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(j)
                order[i][j].y = max(order[i][j].y,order[i][j-1].x+order[i][j-1].y);
            if(i+1<m)
                order[i+1].push_back({M[j][i+1],order[i][j].x+order[i][j].y});
        }
    }
    for(int i = 0;i<n;i++)
        cout<<order[m-1][i].x+order[m-1][i].y<<" ";
    cout<<endl;
    return 0;
}  
