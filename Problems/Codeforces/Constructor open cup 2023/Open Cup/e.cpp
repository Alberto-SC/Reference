#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'


using namespace std;

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;  
        cout<<(1ll<<(n-1))<<endl;
    }
    return 0;
}

