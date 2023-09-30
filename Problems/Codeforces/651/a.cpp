#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n&1)n--;
        cout<<n/2<<endl;

    }
    return 0;
}

