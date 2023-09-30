#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n%4!= 0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}