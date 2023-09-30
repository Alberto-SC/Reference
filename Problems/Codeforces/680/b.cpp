#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        cout<<max(a+b,c+d)<<endl;
    }
    return 0;
}

