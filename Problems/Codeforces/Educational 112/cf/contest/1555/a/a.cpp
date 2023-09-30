#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        if(n%6 == 0)
            cout<<(n/6)*15<<endl;
        else if(n%8 ==0)
            cout<<(n/8)*20<<endl;
        else if(n%10==0)
            cout<<(n/10)*25<<endl;
        else if(n<=6)
            cout<<15<<endl;
        else{
            x = min(((n/6)*15)+15,((n/8)*20)+20);
            x = min(x,((n/10)*25)+25);
            cout<<x<<endl;
        }
    }
    return 0;
}  
