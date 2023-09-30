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
        int x = 4*n;
        for(int i = x/2;i<=x-2;i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}

