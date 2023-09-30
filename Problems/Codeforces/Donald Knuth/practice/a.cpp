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
        n = s.size();
        if(n<=10){
            cout<<s<<endl;
            continue;
        }
        cout<<s[0]<<s.size()-2<<s.back()<<endl;
    }
    return 0;
}  
