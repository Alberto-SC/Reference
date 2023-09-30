#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k; 
        vector<vector<char>> grid(n,vector<char>(n,'.'));
        for(int i = 0;i<n;i+=2){
            grid[i][i] = 'R';
            k--;
            if(!k)break;
        }
        if(k)cout<<-1<<endl;
        else {
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    cout<<grid[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}  
