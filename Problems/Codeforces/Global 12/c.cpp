#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<string> grid(n);
        for(auto &c:grid)cin>>c;
        vector<string> changes[3];
        vector<int> C(3);
        changes[0] = grid;
        changes[1] = grid;
        changes[2] = grid;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]== '.')continue;
                changes[(i+j)%3][i][j]= 'O';
                C[(i+j)%3]++;
            }
        }
        if(C[0]<=C[1] && C[0]<=C[2])
            grid = changes[0];
        else if(C[1]<=C[2] && C[1]<=C[0])
            grid = changes[1];
        else 
            grid = changes[2];

        for(auto c:grid)cout<<c<<endl;

    }
    return 0;
}  

