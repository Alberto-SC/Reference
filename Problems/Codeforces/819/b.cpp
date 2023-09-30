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
        if(m<n)cout<<"No"<<endl;
        else if(n&1){
            cout<<"Yes"<<endl;
            for(int i = 0;i<n-1;i++)cout<<1<<" ";
            cout<<m-(n-1)<<endl;
        }
        else{
            if(m&1)cout<<"No"<<endl;
            else{
                cout<<"Yes"<<endl;
                for(int i = 0;i<n-2;i++)cout<<1<<" ";
                int x = (m-(n-2))/2;
                cout<<x<<" "<<x<<endl;
            }
        }
    }
    return 0;
}