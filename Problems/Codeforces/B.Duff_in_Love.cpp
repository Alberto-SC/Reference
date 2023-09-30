#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli n;
    cin>>n;
    lli ans = 1;
    for(lli i = 2;i*i<=n;i++){
        if(n%i== 0)ans*=i;
        while(n%i == 0){n/=i;}
    }
    cout<<ans*n<<endl;
}