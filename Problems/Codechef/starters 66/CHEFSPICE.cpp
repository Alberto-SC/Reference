#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m,k;
    while(T--){
        cin>>n>>m>>k;
        for(int i = 1;i*i<=k;i++){
            if(k%i==0){
                // divs.push_back(i);
                // if(k/i !=i)divs.push_back(k/i);
            }
        }
        for(int x = 1;x<=n;x++){
            for(int y = 0;y<m;y++){
                cout<<(x*m)+(y*n)-(x*y)<<" ";
            }
            cout<<endl;j
        }
    }
    return 0;
}