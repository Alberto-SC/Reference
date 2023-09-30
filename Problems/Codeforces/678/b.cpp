#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<int>> grid(n,vector<int> (n,0)); 
        if(n == 2){cout<<"1 1\n1 1"<<endl;continue;}
        for(int i = 0;i<n;i++){
            for(int j = 0;j<3;j++){
                grid[i][(i+j)%n] =1;
            }
        }
        for(int i = 0;i<n;i++){ 
            for(int j = 0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    
    }
    return 0;
}

