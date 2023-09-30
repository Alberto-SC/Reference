#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        char M[n][m];
        int mx1 = 0,mx2 = 0;
        for(int i= 0;i<n;i++){
            int cont1 = 0,cont2 = 0;
            for(int j = 0;j<m;j++){
                cin>>M[i][j];
                if((j+i)%2==0)cont1+=M[i][j]== '1';
                else cont2+=M[i][j]== '1';
            }
            mx1 = max(mx1,cont1);
            mx2 = max(mx2,cont2);
        }
        cout<<mx1+mx2<<endl;
    }
    return 0;
}