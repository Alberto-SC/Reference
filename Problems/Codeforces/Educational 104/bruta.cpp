#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        int cont = 0;
        for(int i = 1;i<=n;i++){
            for(int j = i;j<=n;j++){
                for(int k =j;k<=n;k++){
                    if((i*i)-j== k && (i*i)+(j*j)== k*k){
                        cont++;
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                    }
                }
            }
        }
        cout<<cont<<endl;
    }
}