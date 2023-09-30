#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int a,b,t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(((a+b)%3) || max(a,b)>(2*min(a,b)))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}