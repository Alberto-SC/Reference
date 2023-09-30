#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int x = 0;
        for(int i = 0;i<32;i++){
            if((a>>i)&1 && (b>>i)&1){
                x|=(1<<i);
            }
        }
        int y = (x^a) +(x^b);
        cout<<y<<endl;
    }
    return 0;
}

