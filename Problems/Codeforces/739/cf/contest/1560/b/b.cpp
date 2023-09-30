#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int n = max({a,b,c});
        if(n&1)n++;
        if(a>b)swap(a,b);
        int f = n/2;
        if(b<=f|| b<(f+a)){
            cout<<-1<<endl;
        }
        else {
            n= (b-a)*2;
            f = n/2;
            if(c<=f)
                cout<<f+c<<endl;
            else    
                cout<<c-f<<endl;
        }

    }
    return 0;
}  
