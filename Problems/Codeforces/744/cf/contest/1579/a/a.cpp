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
        int ca = 0,cb = 0,cc = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='A')ca++;
            else if(s[i]=='B')cb++;
            else cc++;
        }
        if(cb == ca+cc)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
