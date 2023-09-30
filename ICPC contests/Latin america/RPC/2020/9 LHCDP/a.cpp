#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli n,k;
    cin>>n>>k;
    if(n == 1)cout<<k<<endl;
    else {
        cout<<k+ ((k-2)*(n-1))<<endl;
    }
    return 0;
}

