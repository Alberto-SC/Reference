#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>x;
        int ans = 0;
        for(int i = 1;i<=x;i++){
            int y = (i*(i+1))/2;
            if(y>=x){
                if(y == x+1)ans = i+1;
                else ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}  

