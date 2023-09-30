#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,N,C,B,W,R,G;
    cin>>t;
    while(t--){
        cin>>N>>C>>B>>W>>R>>G;
        if(C*B>=N)cout<<N<<endl;
        else{
            int x = C*B;
            int rest = N-x;
            if(R>=rest)
                cout<<x+(rest*C)<<endl;
            else cout<<"Don't even try!"<<endl;
        }
    }
    return 0;
}  
