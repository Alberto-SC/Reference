#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
int g[107][107];
int main(){__
    int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>g[i][j];
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if((i+j)%2 != g[i][j]%2)
                    g[i][j]++;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cout<<g[i][j]<<" \n"[j ==m-1];
    }
    return 0;
}  

