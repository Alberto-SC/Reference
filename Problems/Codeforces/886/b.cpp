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
        int mx=  0,id = 0;
        for(int i = 0;i<n;i++){
            int a,b;
            cin>>a>>b;
            if(a<=10 && b>mx){
                mx = b;
                id = i+1;
            }
        }
        cout<<id<<endl;
    }
    return 0;
}