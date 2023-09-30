#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool flip = false;
        int a = 0,b = 1;
        for(int i = 0;i<n;i++){
            flip = true;
            if(i%2==0)swap(a,b);
            for(int j = 0;j<m;j++){
                if(j%2==0)flip = !flip;
                if(flip){
                    if(j&1)cout<<a<<" ";
                    else cout<<b<<" ";
                }
                else{
                    if(j&1)cout<<b<<" ";
                    else cout<<a<<" ";
                }
            }     
            swap(a,b);
            cout<<endl;
        }
        cout<<endl;
    }
}
