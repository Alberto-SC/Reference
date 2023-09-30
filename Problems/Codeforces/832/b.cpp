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
        int k = (n+1)/2;
        cout<<k<<endl;
        for(int i = 0,idx = 0;i<k;i++,idx+=3){
            cout<<idx+1<<" "<<(((n*3)-1)-idx)+1<<endl;
        }
    }
    return 0;
}