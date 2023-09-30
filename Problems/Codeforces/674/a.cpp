#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        if(n == 1 || n == 2)cout<<1<<endl;
        else {
            n-=2;
            if(n%x == 0)cout<<(n/x)+1<<endl;
            else cout<<(n/x)+2<<endl;
        }
    }
    return 0;
}

