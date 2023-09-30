#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n%2 == 1 && k%2==0)cout<<"NO"<<endl;
        else if(n%2==0 && k%2==1)cout<<"NO"<<endl;
        else if((k*k)>n) cout<<"NO"<<endl;    
        else cout<<"YES"<<endl;

    }
    return 0;
}

