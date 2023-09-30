#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int n;
    cin>>n;
    int x = 0;
    while(n){
        x+=n/5;
        n/=5;
    }
    cout<<x<<endl;
    return 0;
}