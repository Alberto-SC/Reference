#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        int l = 1,r = n*n;

        int num = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<num<<" ";
                num+=2;
                if(num>n*n)num = 2;
            } 
            cout<<endl;
            
        }
    }
    return 0;
}

 


