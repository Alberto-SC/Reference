#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t ,n,m,x,y;
    cin>>n>>m>>x>>y;
    int nx = x;
    for(int j = 0;j<m;j++){
        for(int i = 0;i<n;i++){
            cout<<nx<<" "<<y<<endl;
            if(i <n-1){

                nx++;
                if(nx == n+1)nx = 1;
            }
        }    
        y++;
        if(y ==m+1)y = 1;
    }

    return 0;
}

