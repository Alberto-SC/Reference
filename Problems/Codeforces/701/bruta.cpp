#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int cont = 0;
        for(int i = 1;i<=x;i++){
            for(int j = 1;j<=y;j++){
                if(i/j == i%j){
                    // if(i%j ==2)cout<<i<<" "<<j<<endl;
                    cont++;
                }
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}  

