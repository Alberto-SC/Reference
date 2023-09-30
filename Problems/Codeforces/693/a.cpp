#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,h,w;
    cin>>t;
    while(t--){
        cin>>h>>w>>n;
        lli x = 1;
        while(h%2 == 0){
            x*=2;
            h/=2;
        }
        while(w%2 == 0){
            x*=2;
            w/=2;
        }
        if(x>=n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  

