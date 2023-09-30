#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n;
    cin>>n;
    int N = n*4;
    int ans = 0;
    for(int mask = 0;mask<(1<<N);mask++){
        int M[4][n];
        int x = 0,y = 0;
        for(int i = 0;i<N;i++){
            M[x][y] = (mask>>i)&1;
            y++;
            if(y== n)y = 0,x++;
        }    
        set<int> st;
        for(int k = 0;k<=n-4;k++){
            int cont = 0;
            for(int i = 0;i<4;i++){
                for(int j = 0;j<4;j++){
                    cont+=M[i][k+j];
                }
            }
            st.insert(cont);
        }
        if(st.size()==1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}