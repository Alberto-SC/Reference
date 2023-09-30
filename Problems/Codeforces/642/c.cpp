#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        lli ans = 0;
        int first = 3;
        if(n == 1)cout<<0<<endl;
        else {
            lli size;
            for(int i = 1;i<=n/2;i++){
                size=first*2+((first-2)*2);
                ans+= size*i;
                first+=2;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}