
#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int n,a,b,c,d;

    cin>>n>>a>>b>>c>>d;
    
    if(abs(b-c)>1 || (a && d && b+c == 0)){
        cout<<"No"<<endl;
    }
    else 
        cout<<"Yes"<<endl;

    return 0;
}

