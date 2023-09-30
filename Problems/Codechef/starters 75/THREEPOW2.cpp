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
        string s;
        cin>>s;
        int idx = 0,cont = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== '1'){
                cont++;
                idx = i;
            }
        }

        if(cont == 2 || cont ==3){
            cout<<"YES"<<endl;
        }
        else if(cont == 1 && n-idx>=3){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}