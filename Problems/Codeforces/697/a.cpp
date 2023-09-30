#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = true;
        for(int i = 0;i<=59;i++){
            if(n== (1ll<<i))flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  

