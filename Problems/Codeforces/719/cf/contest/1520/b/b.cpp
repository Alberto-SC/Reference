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
        int ans = (s.size()-1)*9;
        int n = s.size();
        string mn(n,'1');
        for(int i = 1;i<=9;i++){
            for(int j = 0;j<n;j++){
                mn[j] = char(i+'0');
            }
            if(mn<=s)ans++;
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
