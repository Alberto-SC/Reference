#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<fixed<<setprecision(0);
        if(n==2 || n== 1)cout<<1<<endl;
        else 
            cout<<ceil(n/2.0)<<endl;
    }
    return 0;
}