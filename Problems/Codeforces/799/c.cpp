#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t,n;
    cin>>t;
    while(t--){
        char grid[8][8];
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                cin>>grid[i][j];
            }
        }
        bool flag = false;
        for(int i = 1;i<7;i++){
            for(int j = 1;j<7;j++){
                int cont = 0;
                cont+=grid[i-1][j-1]=='#';
                cont+=grid[i+1][j+1]=='#';
                cont+=grid[i-1][j+1]=='#';
                cont+=grid[i+1][j-1]=='#';
                if(cont == 4){
                    cout<<i+1<<" "<<j+1<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
    }
    return 0;
} 