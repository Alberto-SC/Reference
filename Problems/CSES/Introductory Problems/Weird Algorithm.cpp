#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2==0)n/=2;
        else n*=3,n++;
    }
    cout<<1<<endl;

    return 0;
}