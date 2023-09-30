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
        cout<<2<<endl;
        int last = n;
        for(int i = n-1;i>=1;i--){
            cout<<i<<" "<<last<<endl;
            last = (i+last+1)/2;
        }       

    }
    return 0;
}

