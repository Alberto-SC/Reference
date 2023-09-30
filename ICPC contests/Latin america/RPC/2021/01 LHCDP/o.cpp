#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,p,e;
    cin>>t;
    while(t--){
        cin>>p>>e;
        if((p-e)>=10)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  

