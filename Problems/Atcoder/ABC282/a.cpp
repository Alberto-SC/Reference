#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        for(int i = 0;i<n;i++){
            cout<<char(i+'A');
        }
        cout<<endl;
    }
    return 0;
}