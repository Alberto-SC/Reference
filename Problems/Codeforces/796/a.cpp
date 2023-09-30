#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        int f = -1;
        int cont = 0;
        for(int i = 0;i<31;i++){
            if((n>>i)&1){
                if(f== -1)
                    f = i;
                cont++;
            }
        }
        if(n == 1)cout<<3<<endl;
        else if(n&1)cout<<(1<<f)<<endl;
        else if(cont ==1)cout<<((1<<f)+1)<<endl;
        else cout<<(1<<f)<<endl;
        
    }
    return 0;
}