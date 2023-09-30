#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        char M[n][m];
        int x = -1,y = -1;
        bool flag = true;
        for(int i = 0;i<n;i++){   
            for(int j = 0;j<m;j++){
                cin>>M[i][j];
                if(M[i][j] == 'R'){
                    if(x==-1){
                        x = i,y = j;
                    }
                    else if(i<x || j<y)flag = false;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}
