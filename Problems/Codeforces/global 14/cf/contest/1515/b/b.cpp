#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n&1)cout<<"NO"<<endl;
        else{
            if(n%4==0){
                int y = n/4;
                int s = sqrt(y);
                if(s*s==y)cout<<"YES"<<endl;
                else {
                    y = n/2;
                    s = sqrt(y);
                    if(s*s== y)cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }
            }
            else {
                int y = n/2;
                int s = sqrt(y);
                if(s*s== y)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}  
