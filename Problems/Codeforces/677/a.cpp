#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        int x = n%10;
        int ans = (x-1)*10;
        int cont = 0;
        while(n){
            n/=10;
            cont++;
        }
        cout<<ans+(cont*(cont+1))/2<<endl;
    }
    return 0;
}

