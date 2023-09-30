#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        for(auto &c:s){
            c = tolower(c);
        }
        if(s=="yes")cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
