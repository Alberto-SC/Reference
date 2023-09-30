#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int shots = a+b+c;
        int mn = min({a,b,c});
        if(shots%9 == 0 && mn >= shots/9)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  

