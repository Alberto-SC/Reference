#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        int cont = 0;
        for(int i = 1;i<=200000;i++){
            for(int j = 1;j<=200000;j++){
                if(i*j>n)break;
                for(int k = 1;k<=200000;k++){
                    if(i*j*k>n)break;
                    if(i*j*k<= n){
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                        cont++;
                    }
                }
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}  
