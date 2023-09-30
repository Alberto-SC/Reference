#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int x = b+1;
        int y = x/2+ (x%2);
        // cout<<y<<endl;
        if(a>=y)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

