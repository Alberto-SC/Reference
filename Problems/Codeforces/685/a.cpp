#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<0<<endl;
        else if(n ==2)cout<<1<<endl;
        else if(n ==3)cout<<2<<endl;
        else if(n&1)cout<<3<<endl;
        else cout<<2<<endl;
    }
    return 0;
}  

