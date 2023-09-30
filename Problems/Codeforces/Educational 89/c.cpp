#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
int main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> grid(n);
        vector<pair<int,int>> distances(n+m);
        for(int i = 0;i<n;i++){
            grid[i].resize(m);
            for(auto &c:grid[i])cin>>c;
        } 
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int dist = i+j; 
                if(grid[i][j]== 1)
                    distances[dist].x++; 
                else 
                    distances[dist].y++;
            }
        }
        int ans = 0;
        for(int i = 0;i<((n+m)-1)/2;i++){
            int ones = distances[i].x+distances[((n+m)-2)-i].x;
            int two = distances[i].y+distances[((n+m)-2)-i].y;
            // cout<<"I: "<<i<<" "<<ones<<" "<<two<<endl;
            ans+= min(ones,two);
        }   
        cout<<ans<<endl;
    }
    return 0;
}  

