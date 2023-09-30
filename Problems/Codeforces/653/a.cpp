#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    int t,n,x,y,z;
    cin>>t;
    while(t--){
        cin>>x>>y>>n;
        int z = n/x;
        z= (z*x)+y;
        // cout<<z<<endl;
        if(z>n)z-=x;
        cout<<z<<endl;
    }
    return 0;
}