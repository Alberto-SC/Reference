#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    lli t,n,r,x;
    cin>>t;
    while(t--){
        cin>>n>>r;
        if(n<=r){
            x = n-1;
            x = (x*(x+1))/2;
            cout<<x+1<<endl;
        }
        else {
            x = r;
            x = (x*(x+1))/2;
            cout<<x<<endl;
        }
    }
    return 0;
}